#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 1000;
struct Pos {
  int x, y;
  Pos() { x = 0, y = 0; };
  Pos operator-(const Pos &b) {
    Pos t;
    t.x = x - b.x, t.y = y - b.y;
    return t;
  }
  Pos operator+(const Pos &b) {
    Pos t;
    t.x = x + b.x, t.y = y + b.y;
    return t;
  };
} a[maxn], target;
int n;
string s;
void mov(char ch, struct Pos &a) {
  if (ch == 'U')
    a.y++;
  else if (ch == 'D')
    a.y--;
  else if (ch == 'L')
    a.x--;
  else if (ch == 'R')
    a.x++;
}
bool check(int len) {
  int l = 0;
  for (int r = len; r < n; r++, l++) {
    Pos pos3 = a[n + 1], pos2 = a[r], pos1 = a[l];
    Pos offset = pos3 - pos2 + pos1;
    Pos need = offset - target;
    if ((abs(need.x) + abs(need.y)) <= len &&
        ((abs(need.x) + abs(need.y)) % 2 == len % 2))
      return true;
  }
  return false;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie();
  cin >> n >> s;
  cin >> target.x >> target.y;
  s.insert(s.begin(), '#');
  struct Pos pos;
  for (int i = 1; i <= n; i++) {
    mov(s[i], pos);
    a[i] = pos;
  }
  a[n + 1] = a[n];
  int l = 0, r = n + 1, mid = (l + r) / 2;
  while (l < r) {
    if (check(mid))
      r = mid;
    else
      l = mid + 1;
    mid = (l + r) / 2;
  }
  cout << (mid == n + 1 ? -1 : mid) << endl;
}
