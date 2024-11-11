#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int N = 2e6 + 13, M = N;
int i, j, k, n, m;
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  if (b == 0) return a;
  if (a == b) return a;
  if (a > b) return gcd(a % b, b);
  return gcd(a, b % a);
}
void print(vector<long long>& A) {
  for (k = 0; k < A.size(); k++) {
    cout << A[k] << " ";
  }
  cout << endl;
}
void print(vector<int>& A) {
  for (k = 0; k < A.size(); k++) {
    cout << A[k] << " ";
  }
  cout << endl;
}
long long C(long long n, long long r) {
  long long p = 1, k = 1;
  if (n - r < r) r = n - r;
  if (r != 0) {
    while (r) {
      p *= n;
      k *= r;
      long long m = gcd(p, k);
      p /= m;
      k /= m;
      n--;
      r--;
    }
  } else
    p = 1;
  return p;
}
vector<int> v;
bool check(int mid, string s, string t) {
  string a;
  set<int> st;
  for (int i = 0; i < mid; i++) st.insert(v[i]);
  for (int i = 0; i < s.size(); i++) {
    if (!st.count(i + 1)) a.push_back(s[i]);
  }
  int i = 0;
  int j = 0;
  while (i < a.size()) {
    if (a[i] == t[j]) j++;
    if (j == t.size()) break;
    i++;
  }
  return j == t.size();
}
void solve() {
  string s, t;
  cin >> s >> t;
  int n = s.size();
  v = vector<int>(n);
  for (i = 0; i < n; i++) cin >> v[i];
  int lo = 0;
  int hi = n;
  while (lo < hi) {
    int mid = (hi + lo + 1) / 2;
    if (check(mid, s, t))
      lo = mid;
    else
      hi = mid - 1;
  }
  cout << lo << endl;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int z = 1;
  while (z--) {
    solve();
  }
  return 0;
}
