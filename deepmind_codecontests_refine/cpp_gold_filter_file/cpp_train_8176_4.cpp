#include <bits/stdc++.h>
using namespace std;
void sep(string SS = "BLOCK") {
  cout << "-------------" << SS << "-----------------\n";
}
template <typename t>
void pr(t a) {
  cout << a << endl;
}
template <typename t>
void prs(t a) {
  cout << a << " ";
}
template <typename T>
void debugv(vector<T> arr) {
  for (auto t : arr) cout << t << " ";
  cout << "\n";
}
template <typename T>
void debugarr(T arr, int n) {
  for (int i = 0; i < n; i++) cout << arr[i] << " ";
  cout << "\n";
}
template <typename T>
void chmax(T& a, T b) {
  if (a < b) a = b;
}
template <typename T>
void chmin(T& a, T b) {
  if (a > b) a = b;
}
long long min(long long a, long long b) { return a < b ? a : b; }
long long max(long long a, long long b) { return a > b ? a : b; }
const int maxn = 4e6 + 100;
const long long INF = 1e18;
long long a[maxn], n, m, t, k, q;
unordered_map<long long, long long> u;
string s;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> s;
  n = s.size();
  for (long long i = 0; i + 26 <= n; i++) {
    string t = s.substr(i, 26);
    sort(t.begin(), t.end());
    long long qs = 0, st = 0;
    vector<long long> ms;
    for (long long j = 0; j < 26; j++) {
      if (t[j] == '?')
        ++qs;
      else {
        while (st < 26 && (long long)(t[j] - 'A') != st) {
          ms.push_back(st);
          ++st;
        }
        ++st;
      }
    }
    while (st < 26) ms.push_back(st++);
    if (ms.size() == qs) {
      long long ac = 0;
      for (long long j = i; j < i + 26; j++)
        if (s[j] == '?') s[j] = (char)(ms[ac++] + 'A');
      for (long long j = i - 1; j >= 0; j--)
        if (s[j] == '?') s[j] = 'A';
      for (long long j = i + 26; j < n; j++)
        if (s[j] == '?') s[j] = 'A';
      pr(s);
      exit(0);
    }
  }
  pr(-1);
}
