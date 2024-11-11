#include <bits/stdc++.h>
using namespace std;
template <class T>
void CIN(T &a) {
  cin >> a;
}
template <class T>
void CIN(T &a, T &b) {
  cin >> a >> b;
}
template <class T>
void CIN(T &a, T &b, T &c) {
  cin >> a >> b >> c;
}
template <class T>
void CIN(T &a, T &b, T &c, T &d) {
  cin >> a >> b >> c >> d;
}
template <class T>
void PI(T a) {
  cout << a << endl;
}
template <class T>
void PI(T a, T b) {
  cout << a << " " << b << endl;
}
template <class T>
void PIS(T a) {
  cout << a << " ";
}
template <class T>
T abs(T a) {
  return a < 0 ? -a : a;
}
const int inf = 0x7fffffff;
int n, nxt[300010][26];
char s[300010];
bool v[26];
long long ans[27];
int main() {
  cin >> s;
  n = strlen(s);
  int i, j;
  for (i = 0; i < (int)(26); ++i) nxt[n][i] = n;
  for (i = n - 1; i >= 0; --i) {
    for (j = 0; j < (int)(26); ++j) nxt[i][j] = nxt[i + 1][j];
    if (i != n - 1) nxt[i][s[i + 1] - 'a'] = i + 1;
  }
  for (i = 0; i < (int)(n); ++i) {
    memset(v, 0, sizeof(v));
    v[s[i] - 'a'] = 1;
    int k = i, d = 1;
    while (k < n) {
      int minn = n, tmp;
      for (j = 0; j < (int)(26); ++j)
        if (!v[j] && nxt[k][j] < minn) {
          minn = nxt[k][j];
          tmp = j;
        }
      v[tmp] = 1;
      ans[d++] += minn - k;
      k = minn;
    }
  }
  memset(v, 0, sizeof(v));
  for (i = 0; i < (int)(n); ++i) v[s[i] - 'a'] = 1;
  int tot = 0;
  for (i = 0; i < (int)(26); ++i) tot += v[i];
  PI(tot);
  for (i = 1; i <= (int)(tot); ++i) PI(ans[i]);
  return 0;
}
