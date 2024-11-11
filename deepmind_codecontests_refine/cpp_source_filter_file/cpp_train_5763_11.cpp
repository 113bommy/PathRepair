#include <bits/stdc++.h>
using namespace std;
const double EPS = 0.0000001;
const double PI = acos(-1);
const long long INFLL = 0x7FFFFFFFFFFFFFFF;
const int INF = 0x7FFFFFFF;
template <typename T>
inline void next(T &num) {
  char c;
  num = 0;
  do {
    c = getchar_unlocked();
  } while (c != EOF && c == ' ' && c == '\n' && c == '\t');
  int sign = (c == '-' ? -1 : 1);
  if (c != '-') num += (c - '0');
  while ((c = getchar_unlocked()) != EOF && c != '\n' && c != '\t' &&
         c != ' ') {
    num *= 10;
    num += (c - '0');
  }
  num *= sign;
}
inline string getstr() {
  string str;
  char k;
  while ((k = getchar_unlocked()) == ' ' || k == '\n') {
    k = getchar_unlocked();
    if (k == ' ' || k == '\n')
      continue;
    else
      break;
  }
  str.push_back(k);
  while ((k = getchar_unlocked()) != EOF && k != '\n' && k != '\t' &&
         k != '\v' && k != '\0' && k != ' ')
    str.push_back(k);
  return str;
}
long long sumx[1003], sumy[1003], ansx[1003], ansy[1003];
long long sqr(int x) { return (long long)x * x; }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m, t;
  cin >> n >> m;
  for (int i = int(1), _b = int(n); i <= _b; i++)
    for (int j = int(1), _b = int(m); j <= _b; j++) {
      cin >> t;
      sumx[j] += t;
      sumy[i] += t;
    }
  for (int i = int(0), _b = int(n); i <= _b; i++) {
    for (int j = int(1), _b = int(n - i); j <= _b; j++)
      ansx[i] += sumy[i + j] * sqr(j * 4 - 2);
    for (int j = int(1), _b = int(i); j <= _b; j++)
      ansx[i] += sumy[i - j + 1] * sqr(j * 4 - 2);
  }
  for (int j = int(0), _b = int(m); j <= _b; j++) {
    for (int i = int(1), _b = int(m - j); i <= _b; i++)
      ansy[j] += sumx[i + j] * sqr(i * 4 - 2);
    for (int i = int(1), _b = int(j); i <= _b; i++)
      ansy[j] += sumx[j - i + 1] * sqr(i * 4 - 2);
  }
  long long ans = INF, x = -1, y = -1;
  for (int i = int(0), _b = int(n); i <= _b; i++)
    for (int j = int(0), _b = int(m); j <= _b; j++)
      if (ansx[i] + ansy[j] < ans) {
        ans = ansx[i] + ansy[j];
        x = i;
        y = j;
      }
  cout << ans << '\n' << x << ' ' << y;
  return 0;
}
