#include <bits/stdc++.h>
using namespace std;
void input(vector<long long int> &arr) {
  for (int i = 0; i < arr.size(); i++) cin >> arr[i];
}
void output(vector<long long int> arr) {
  for (int i = 0; i < arr.size(); i++) cout << arr[i] << " ";
  cout << "\n";
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int power(long long int a, long long int b) {
  if (b == 0) return 1;
  if (b == 1) return a;
  long long int smallans = power(a, b / 2);
  long long int myans = (smallans * smallans) % 1000000007;
  if ((b & 1)) myans = (myans * a) % 1000000007;
  return myans;
}
long long int multiply(long long int a, long long int b) {
  long long int ans = ((a % 1000000007) * (b % 1000000007)) % 1000000007;
  return ans;
}
long long int add(long long int a, long long int b) {
  long long int ans = ((a % 1000000007) + (b % 1000000007)) % 1000000007;
  return ans;
}
long long int subtract(long long int a, long long int b) {
  long long int ans = ((a % 1000000007) - (b % 1000000007)) % 1000000007;
  if (ans < 0) ans += 1000000007;
  return ans;
}
long long int divide(long long int a, long long int b) {
  return multiply(a, power(b, 1000000007 - 2));
}
struct hash_pair {
  template <class T1, class T2>
  size_t operator()(const pair<T1, T2> &p) const {
    auto hash1 = hash<T1>{}(p.first);
    auto hash2 = hash<T2>{}(p.second);
    return hash1 ^ hash2;
  }
};
void update(vector<long long int> &tree, long long int index,
            long long int val) {
  index++;
  while (index < tree.size()) {
    tree[index] = (tree[index] + val) % 1000000007;
    index += index & (-index);
  }
}
long long int calculate(vector<long long int> &tree, long long int index) {
  long long int sum = 0;
  index++;
  while (index > 0) {
    sum = (sum + tree[index]) % 1000000007;
    index -= index & (-index);
  }
  return sum;
}
long long int findpar(long long int p, vector<long long int> &parent) {
  if (parent[p] == p) return p;
  parent[p] = findpar(parent[p], parent);
  return parent[p];
}
void merge(long long int a, long long int b, vector<long long int> &parent,
           vector<long long int> &size_) {
  a = findpar(a, parent);
  b = findpar(b, parent);
  if (a != b) {
    if (size_[a] < size_[b]) swap(a, b);
    parent[b] = a;
    size_[a] += size_[b];
  }
}
void sieve(vector<bool> &primes, vector<long long int> &count) {
  for (int i = 2; i < primes.size(); i++) {
    if (primes[i]) {
      count.push_back(i);
      for (int j = i * i; j < primes.size(); j += i) primes[j] = false;
    }
  }
}
void solve() {
  long long int n;
  cin >> n;
  vector<long long int> arr(n, 0);
  input(arr);
  vector<long long int> cats(1e5 + 5, 0);
  map<long long int, long long int> freq;
  for (int i = 0; i < n; i++) cats[arr[i]]++;
  for (int i = 0; i < cats.size(); i++) {
    if (cats[i] > 0) freq[cats[i]]++;
  }
  long long int ans = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (freq.size() == 2) {
      auto it = freq.begin();
      vector<long long int> par;
      for (auto keys : freq) {
        par.push_back(keys.first);
      }
      for (auto keys : freq) {
        if (keys.second == 1 && (keys.first == par[0] + 1 ||
                                 keys.first == par[1] + 1 || keys.first == 1)) {
          cout << (i + 1) << "\n";
          return;
        }
      }
    }
    freq[cats[arr[i]]]--;
    cats[arr[i]]--;
    if (freq[cats[arr[i]] + 1] == 0) freq.erase(cats[arr[i]] + 1);
    if (cats[arr[i]] > 0) freq[cats[arr[i]]]++;
    if (freq.size() < 2) {
      cout << i + 1 << "\n";
      return;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
