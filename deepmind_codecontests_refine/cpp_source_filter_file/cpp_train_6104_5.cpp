#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7;
const long long N = 1e5 + 10;
const long long IM = 1e15 + 37;
const long double PI = 3.1415926535897932384;
inline void PP(long long n) { cout << n << " "; }
void PV(vector<long long> v) {
  for (long long i = 0; i < v.size(); i++) cout << v[i] << " ";
  cout << "\n";
}
void PVV(vector<pair<long long, long long> > v) {
  for (long long i = 0; i < v.size(); i++)
    cout << v[i].first << " " << v[i].second << "\n";
}
void PA(long long v[], long long n, long long x = 0) {
  for (long long i = x; i < n + x; i++) cout << v[i] << ' ';
  cout << "\n";
}
void IN(long long a[], long long n, long long x = 0) {
  for (long long i = x; i < n + x; i++) cin >> a[i];
}
inline void op() {}
long long l[N];
string a =
    "What are you doing at the end of the world? Are you busy? Will you save "
    "us?";
string b =
    "What are you doing while sending ? Are you busy? Will you send ?++++";
string s1 = "What are you doing while sending +";
string s2 = "+? Are you busy? Will you send +";
string s3 = "+?";
char solve(long long n, long long k) {
  if (n == 0) {
    return a[k];
  }
  if (k < s1.size())
    return s1[k];
  else if (k < s1.size() + l[n - 1]) {
    return solve(n - 1, k - s1.size());
  } else if (k < s1.size() + l[n - 1] + s2.size()) {
    k = k - s1.size() - l[n - 1];
    return s2[k];
  } else if (k < s1.size() + l[n - 1] + l[n - 1] + s2.size()) {
    k = k - s1.size() - l[n - 1] - s2.size();
    return solve(n - 1, k);
  } else {
    k = k - s1.size() - l[n - 1] - l[n - 1] - s2.size();
    return s3[k];
  }
}
signed main() {
  op();
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string ans = "";
  long long x = a.size();
  l[0] = x;
  long long m = 1e18;
  for (long long i = 1; i < N - 10; i++) {
    l[i] = l[i - 1] * 2 + s1.size() + s2.size() + s3.size();
    l[i] = min(l[i], m);
  }
  long long q;
  cin >> q;
  while (q--) {
    long long n, k;
    cin >> n >> k;
    if (l[n] < k) {
      ans += '.';
      continue;
    }
    k--;
    char c = solve(n, k);
    if (c == '+') c = '"';
    ans += c;
  }
  cout << (ans) << "\n";
  return 0;
}
