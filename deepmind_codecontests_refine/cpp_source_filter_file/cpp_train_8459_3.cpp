#include <bits/stdc++.h>
template <typename T>
inline void read(T &x) {
  char c;
  bool nega = 0;
  while ((!isdigit(c = getchar())) && (c != '-'))
    ;
  if (c == '-') {
    nega = 1;
    c = getchar();
  }
  x = c - 48;
  while (isdigit(c = getchar())) x = x * 10 + c - 48;
  if (nega) x = -x;
}
template <typename T>
inline void writep(T x) {
  if (x > 9) writep(x / 10);
  putchar(x % 10 + 48);
}
template <typename T>
inline void write(T x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  writep(x);
  putchar(' ');
}
template <typename T>
inline void writeln(T x) {
  write(x);
  putchar('\n');
}
using namespace std;
int n, ans = 1, l, r, cur;
bool dd[100005], mi;
vector<int> prime;
int GetA(int x) {
  cout << "A " << x << endl;
  cin >> x;
  return x;
}
int GetB(int x) {
  cout << "B " << x << endl;
  cin >> x;
  return x;
}
int Get(int x) {
  int res = 0;
  for (int i = x; i <= n; i += x)
    if (!dd[i]) {
      ++res;
      dd[i] = 1;
    }
  return res;
}
int Find(int x) {
  int res = x;
  while (1ll * res * x <= n) {
    if (GetA(res * x))
      res *= x;
    else
      break;
  }
  return res;
}
int main() {
  srand(time(NULL));
  cin >> n;
  for (int i = (2); i <= (n); ++i) {
    if (dd[i]) continue;
    prime.push_back(i);
    if (1ll * i * i > n) continue;
    for (int j = i * i; j <= n; j += i) dd[j] = 1;
  }
  memset(dd, 0, sizeof dd);
  l = 0, r = sqrt(prime.size()) - 1;
  cur = n;
  for (int i = 0; i < prime.size(); ++i) {
    int u = GetB(prime[i]);
    int cnt = Get(prime[i]);
    cur -= cnt;
    if (cnt != u) {
      ans *= Find(u);
    }
    if (mi) continue;
    if (i == r) {
      u = GetA(1);
      if (u != cur) {
        for (int j = l; j <= r; ++j) {
          if (GetA(prime[j]) != Get(prime[j])) {
            ans *= Find(prime[j]);
            mi = 1;
            break;
          }
        }
      }
      l = r + 1;
      r = min(r + (int)sqrt(prime.size()), (int)prime.size() - 1);
    }
  }
  cout << "C " << ans;
  return 0;
}
