#include <bits/stdc++.h>
using namespace std;
inline void read(int &x) {
  register int c = getchar();
  x = 0;
  int neg = 0;
  for (; ((c < 48 || c > 57) && c != '-'); c = getchar())
    ;
  if (c == '-') {
    neg = 1;
    c = getchar();
  }
  for (; c > 47 && c < 58; c = getchar()) {
    x = (x << 1) + (x << 3) + c - 48;
  }
  if (neg) x = -x;
}
inline void writeln(int x) {
  char buffor[21];
  register int i = 0;
  int neg = 0;
  if (x < 0) {
    neg = 1;
    x = -x;
  }
  do {
    buffor[i++] = (x % 10) + '0';
    x /= 10;
  } while (x);
  i--;
  if (neg) putchar('-');
  while (i >= 0) putchar(buffor[i--]);
  putchar('\n');
}
int n, x, y, dif[10];
vector<int> s;
void input() { cin >> n >> x >> y; }
void ask(int b) {
  if (s.size() == 0) return;
  cout << "? ";
  int sz = s.size();
  cout << sz << " ";
  for (auto u : s) cout << u << " ";
  cout << '\n';
  int sxor;
  cin >> sxor;
  if (sz % 2 == 0) {
    if (sxor == (x ^ y)) dif[b] = 1;
  } else {
    if (sxor == y) dif[b] = 1;
  };
}
bool Ask(int i) {
  cout << "? ";
  cout << i + 1 << " ";
  for (int j = 0; j <= i; j++) cout << s[j] << " ";
  cout << '\n';
  int s;
  cin >> s;
  return ((s == y) || (s == (y ^ x)));
}
int tim() {
  int curdif;
  s.clear();
  for (int i = 0; i <= 9; i++)
    if (dif[i]) {
      curdif = i;
      break;
    }
  for (int j = 1; j <= n; j++)
    if (((j >> curdif) & 1) == 1) s.push_back(j);
  int low = 0, high = s.size() - 1;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (!Ask(mid))
      low = mid + 1;
    else
      high = mid - 1;
  }
  return low;
}
void solve() {
  for (int i = 0; i <= 9; i++) {
    s.clear();
    for (int j = 1; j <= n; j++)
      if (((j >> i) & 1) == 1) s.push_back(j);
    ask(i);
  }
  int pos = tim();
  cerr << "pos"
       << " = " << pos << '\n';
  int pos2 = pos;
  for (int i = 0; i <= 9; i++)
    if (dif[i]) pos2 = pos2 ^ (1 << i);
  if (pos > pos2) swap(pos, pos2);
  cout << "! " << pos << " " << pos2;
}
int main() {
  ios_base::sync_with_stdio(false);
  input();
  solve();
  return 0;
}
