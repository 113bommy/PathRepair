#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cout << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
bool isV(char x) {
  if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') {
    return 1;
  }
  return 0;
}
bool isP(long long n) {
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) return 0;
  }
  return 1;
}
void fio() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
void print(long long* a, long long n) {
  long long i;
  for (i = 0; i < (long long)n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}
void print2d(long long a[][1000], long long m, long long n) {
  long long i, j;
  for (i = 0; i < (long long)m; i++) {
    for (j = 0; j < (long long)n; j++) {
      cout << setw(2) << a[i][j];
    }
    cout << endl;
  }
}
int32_t main() {
  fio();
  string s;
  cin >> s;
  long long q, i, j, n = s.size();
  cin >> q;
  long long pref[n + 1][26];
  memset(pref, 0, sizeof(pref));
  for (i = 1; i < (long long)n + 1; i++) {
    for (j = 0; j < (long long)26; j++) {
      pref[i][j] = pref[i - 1][j];
    }
    pref[i][s[i - 1] - 'a']++;
  }
  while (q--) {
    long long l, r;
    cin >> l >> r;
    if (l == r)
      cout << "Yes\n";
    else if (s[l - 1] != s[r - 1])
      cout << "Yes\n";
    else {
      long long c = 0;
      for (j = 0; j < (long long)26; j++) {
        if (pref[r][j] - pref[l - 1][j]) c++;
      }
      if (c >= 3)
        cout << "Yes\n";
      else
        cout << "No\n";
    }
  }
}
