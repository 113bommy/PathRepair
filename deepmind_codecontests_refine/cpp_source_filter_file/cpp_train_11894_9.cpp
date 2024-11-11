#include <bits/stdc++.h>
using namespace std;
unsigned long long int fact[1001];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int dr[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dc[8] = {0, 0, 1, -1, -1, 1, 1, -1};
unsigned long long int power(unsigned long long int a, long long int b,
                             long long int mod) {
  unsigned long long int ans = 1;
  a %= mod;
  while (b > 0) {
    if (b & 1) {
      ans = ((ans % mod) * (a % mod)) % mod;
    }
    a = ((a % mod) * (a % mod)) % mod;
    b = b / 2;
  }
  return ans;
}
unsigned long long int MMI(unsigned long long int n, long long int p) {
  return power(n, p - 2, p);
}
unsigned long long int ncr(unsigned long long int n, long long int r,
                           long long int p) {
  if (n < r) return 0;
  if (r == 0) return 1;
  return (fact[n] * MMI(fact[r], p) % p * MMI(fact[n - r], p) % p) % p;
}
class subset {
 public:
  long long int count;
  long long int parent;
};
long long int find(subset subsets[], long long int n) {
  if (subsets[n].parent == n)
    return n;
  else
    return find(subsets, subsets[n].parent);
}
void uneon(subset* subsets, long long int a, long long int b) {
  long long int ap = find(subsets, a);
  long long int bp = find(subsets, b);
  if (subsets[ap].count == subsets[bp].count) {
    subsets[bp].parent = ap;
    subsets[ap].count += subsets[bp].count;
    return;
  } else if (subsets[ap].count > subsets[bp].count) {
    subsets[bp].parent = ap;
    subsets[ap].count += subsets[bp].count;
    return;
  } else if (subsets[ap].count < subsets[bp].count) {
    subsets[ap].parent = bp;
    subsets[bp].count += subsets[ap].count;
    return;
  }
}
bool ispoweroftwo(int x) { return (x && !(x & x - 1)); }
unsigned countbits(unsigned int number) { return (int)log2(number) + 1; }
int extendedeuclid(int a, int b, int* x, int* y) {
  if (a == 0) {
    *x = 0;
    *y = 1;
    return b;
  }
  int x1, y1;
  int gcd = extendedeuclid(b % a, a, &x1, &y1);
  *x = y1 - (b / a) * x1;
  *y = x1;
  return gcd;
}
bool* makesieve(int n) {
  bool* isPrime = new bool[n + 1];
  for (int i = 0; i <= n; i++) {
    isPrime[i] = true;
  }
  isPrime[0] = false;
  isPrime[1] = false;
  for (int i = 2; i * i <= n; i++) {
    if (isPrime[i] == true) {
      for (int j = i * i; j <= n; j += i) {
        isPrime[j] = false;
      }
    }
  }
  return isPrime;
}
bool isprime(long long int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
long long int maxSubArraySum(long long int* a, long long int size) {
  long long int local_max = a[0];
  long long int global_max = a[0];
  long long int sum_so_far = a[0];
  long long int start = 0, end = 0;
  long long int tmp_start = 0;
  for (int i = 1; i < size; i++) {
    sum_so_far = a[i] + local_max;
    if (sum_so_far > a[i]) {
      local_max = sum_so_far;
    } else {
      tmp_start = i;
      local_max = a[i];
    }
    if (global_max < local_max) {
      global_max = local_max;
      start = tmp_start;
      end = i;
    }
  }
  return global_max;
}
long long int MSB(long long int n) {
  for (long long int i = 31; i >= 0; i--) {
    if ((n & (1 << i)) != 0) return i;
  }
  return -1;
}
long long int modulus_of_large_num(string num, long long int a) {
  long long int result = 0;
  for (long long int i = 0; i < num.length(); i++)
    result = (result * 10 + (long long int)num[i] - '0') % a;
  return result;
}
long long int NCR(long long int n, long long int k) {
  long long int ans = 1;
  k = k > n - k ? n - k : k;
  long long int j = 1;
  for (; j <= k; j++, n--) {
    if (n % j == 0) {
      ans *= n / j;
    } else if (ans % j == 0) {
      ans = ans / j * n;
    } else {
      ans = (ans * n) / j;
    }
  }
  return ans;
}
vector<int> factors(int n) {
  vector<int> first;
  for (int i = 2; i * i <= n; i++) {
    while (n % i == 0) {
      first.push_back(i);
      n /= i;
    }
  }
  if (n > 1) first.push_back(n);
  return first;
}
int testcase = 0;
const long long int inf = 1e17;
const int N = 1e3 + 5;
void solve() {
  int n;
  cin >> n;
  if (n < 4) {
    cout << "-1" << endl;
    return;
  }
  int arr[4] = {2, 4, 1, 3};
  int temp = n % 4;
  if (temp == 0) {
    int k = n / 4;
    for (int i = 0; i < k; i++) {
      for (int j = 0; j < 4; j++) cout << arr[j] + 4 * i << " ";
    }
    cout << endl;
    return;
  }
  if (temp == 1) {
    int k = n / 4;
    for (int i = 0; i < k; i++) {
      for (int j = 0; j < 4; j++) cout << arr[j] + 4 * i << " ";
    }
    cout << n << endl;
    return;
  }
  if (temp == 2) {
    int k = n / 4;
    for (int i = 0; i < k - 1; i++) {
      for (int j = 0; j < 4; j++) cout << arr[j] + 4 * i << " ";
    }
    cout << arr[1] + 4 * (k - 1) << " " << n << " " << arr[3] + 4 * (k - 1)
         << " " << arr[0] + 4 * (k - 1) << " " << arr[2] + 4 * (k - 1) << " "
         << n - 1 << endl;
    return;
  } else {
    int k = n / 4;
    for (int i = 0; i < k - 1; i++) {
      for (int j = 0; j < 4; j++) cout << arr[j] + 4 * i << " ";
    }
    cout << arr[1] + 4 * (k - 1) << " " << n - 1 << " " << arr[3] + 4 * (k - 1)
         << " " << arr[0] + 4 * (k - 1) << " " << arr[2] + 4 * (k - 1) << " "
         << n - 2 << " " << n << endl;
    return;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int t = 1;
  cin >> t;
  while (t--) {
    testcase++;
    solve();
  }
}
