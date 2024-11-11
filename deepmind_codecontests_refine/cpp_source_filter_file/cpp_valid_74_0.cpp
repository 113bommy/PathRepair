#include <bits/stdc++.h>
using namespace std;
struct hash_pair {
  template <class T1, class T2>
  size_t operator()(const pair<T1, T2> &p) const {
    auto hash1 = hash<T1>{}(p.first);
    auto hash2 = hash<T2>{}(p.second);
    return hash1 ^ hash2;
  }
};
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int lcm(long long int a, long long int b) {
  return (a / gcd(a, b)) * b;
}
long long int mul(long long int a, long long int b, long long int m) {
  long long int a1 = a / 1000000, a2 = a % 1000000;
  long long int b1 = b / 1000000, b2 = b % 1000000;
  long long int x = a1 * (b1 * 1000000000000LL % m) % m;
  long long int y = (a1 * b2 + a2 * b1) % m * 1000000 % m;
  long long int z = a2 * b2;
  long long int res = (x + y + z) % m;
  return res;
}
long long int mod_pow(long long int a, long long int b, long long int m) {
  long long int x = 1, y = a;
  while (b) {
    if (b & 1) {
      x = mul(x, y, m);
    }
    y = mul(y, y, m);
    b >>= 1;
  }
  return x;
}
string num_str(long long a) { return to_string(a); }
long long int str_num(string str) {
  stringstream ss(str);
  long long int num;
  ss >> num;
  return num;
}
long long int binarySearch(vector<pair<long long int, long long int> > &arr,
                           long long int l, long long int r, long long int x) {
  if (r >= l) {
    long long int mid = l + (r - l) / 2;
    if (arr[mid].first == x) return mid;
    if (arr[mid].first > x) return binarySearch(arr, l, mid - 1, x);
    return binarySearch(arr, mid + 1, r, x);
  }
  return l - 1;
}
vector<long long int> num_binary(long long int num) {
  vector<long long int> bin;
  do {
    bin.push_back(num % 2);
    num /= 2;
  } while (num);
  return bin;
}
long long int binary_num(vector<long long int> &bin) {
  long long int num = 1, sum = 0;
  for (long long int i = 0; i < bin.size(); i++) {
    if (bin[i] != 0) sum += num;
    num *= 2;
  }
  return sum;
}
bool check_prime(long long int n) {
  for (long long int i = 2; i * i <= n; i++)
    if (n % i == 0) return false;
  return true;
}
long long int modInverse(long long int n, long long int p) {
  return mod_pow(n, p - 2, p);
}
long long int nCrModPFermat(long long int n, long long int r, long long int p) {
  if (n < r) return 0;
  if (r == 0) return 1;
  vector<long long int> fac(n + 1);
  fac[0] = 1;
  for (long long int i = 1; i <= n; i++) fac[i] = (fac[i - 1] * i) % p;
  return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) %
         p;
}
class SegementTree {
 private:
  struct Node {
    long long int l, r, val = 0;
    Node *lchild = NULL, *rchild = NULL;
  };
  Node *parent;
  Node *pending;
  long long int make_tree(vector<long long int> &arr, long long int l,
                          long long int r, Node *node, Node *pending_node) {
    node->l = l;
    node->r = r;
    pending_node->l = l;
    pending_node->r = r;
    if (l == r)
      return arr[l];
    else {
      long long int mid = (l + r) / 2;
      node->lchild = new Node;
      node->rchild = new Node;
      pending_node->lchild = new Node;
      pending_node->rchild = new Node;
      node->lchild->val =
          make_tree(arr, l, mid, node->lchild, pending_node->lchild);
      node->rchild->val =
          make_tree(arr, mid + 1, r, node->rchild, pending_node->rchild);
      return node->lchild->val + node->rchild->val;
    }
  }
  long long int lazy_range_update(long long int l, long long int r,
                                  long long int val, Node *node,
                                  Node *pending_node) {
    if (pending_node->val != 0) {
      node->val += (node->r - node->l + 1) * pending_node->val;
      if (node->lchild != NULL) pending_node->lchild->val += pending_node->val;
      if (node->rchild != NULL) pending_node->rchild->val += pending_node->val;
      pending_node->val = 0;
    }
    if (r < node->l || l > node->r)
      return 0;
    else if (l <= node->l && node->r <= r) {
      if (node->lchild != NULL) pending_node->lchild->val += val;
      if (node->rchild != NULL) pending_node->rchild->val += val;
      return (node->r - node->l + 1) * val;
    } else {
      long long int left_node =
          lazy_range_update(l, r, val, node->lchild, pending_node->lchild);
      node->lchild->val += left_node;
      long long int right_node =
          lazy_range_update(l, r, val, node->rchild, pending_node->rchild);
      node->rchild->val += right_node;
      return left_node + right_node;
    }
  }
  long long int lazy_range_sum(long long int l, long long int r, Node *node,
                               Node *pending_node) {
    if (pending_node->val != 0) {
      node->val += (node->r - node->l + 1) * pending_node->val;
      if (node->lchild != NULL) pending_node->lchild->val += pending_node->val;
      if (node->rchild != NULL) pending_node->rchild->val += pending_node->val;
      pending_node->val = 0;
    }
    if (r < node->l || l > node->r)
      return 0;
    else if (l <= node->l && node->r <= r)
      return node->val;
    else
      return lazy_range_sum(l, r, node->lchild, pending_node->lchild) +
             lazy_range_sum(l, r, node->rchild, pending_node->rchild);
  }

 public:
  SegementTree(vector<long long int> &arr) {
    if (arr.size() != 0) {
      parent = new Node;
      pending = new Node;
      parent->val = make_tree(arr, 0, arr.size() - 1, parent, pending);
    }
  }
  void range_update(long long int l, long long int r, long long int val) {
    parent->val += lazy_range_update(l, r, val, parent, pending);
  }
  long long int range_sum(long long int l, long long int r) {
    return lazy_range_sum(l, r, parent, pending);
  }
};
long long int primeFactors(long long int n) {
  long long int ans = 0;
  while (n % 2 == 0) {
    ans++;
    n = n / 2;
  }
  for (long long int i = 3; i * i <= n; i += 2) {
    while (n % i == 0) {
      ans++;
      n = n / i;
    }
  }
  if (n > 2) ans++;
  return ans;
}
long long int floor_sqrt(long long int a) {
  if (a == 0 || a == 1) return a;
  long long int l = 1, r = a, mid, ans;
  while (l <= r) {
    mid = (l + r) / 2;
    if (mid * mid == a) return mid;
    if (mid <= a / mid) {
      l = mid + 1;
      ans = mid;
    } else
      r = mid - 1;
  }
  return ans;
}
template <typename T1>
struct Queue {
  struct Node {
    T1 data;
    Node *next = NULL;
  };
  Node *head = NULL, *tail = NULL;
  long long int len = 0;
  bool empty() { return head == NULL; }
  T1 front() { return head->data; }
  void pop() {
    Node *temp = head;
    head = head->next;
    temp->next = NULL;
    len--;
  }
  void push(T1 data) {
    if (head == NULL) {
      head = new Node;
      head->data = data;
      tail = head;
    } else {
      tail->next = new Node;
      tail = tail->next;
      tail->data = data;
    }
    len++;
  }
  long long int size() { return len; }
};
void solve() {
  long long int tc;
  cin >> tc;
  for (long long int t = 1; t <= tc; t++) {
    long long int a, b;
    cin >> a >> b;
    set<int> ans;
    for (int i = 0; i <= min(a, b); i++) {
      ans.insert(abs(a - ((a + b) / 2) + 2 * i));
      ans.insert(abs(a - ((a + b) / 2 + (a + b) % 2) + 2 * i));
    }
    cout << ans.size() << "\n";
    for (auto i : ans) cout << i << " ";
    cout << "\n";
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
