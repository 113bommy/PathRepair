#include <bits/stdc++.h>
using namespace std;
int t, n, m, i, j, ans, k, a, b, c, d, e, row, col, pos;
string s, s2, s3, s4;
bool visited[600];
int ar[(int)(1e6 + 10)];
void brainfuck();
void rec(int idx, int x);
int main() {
  ios_base::sync_with_stdio(NULL);
  cin.tie(NULL);
  cout.tie(NULL);
  brainfuck();
  return 0;
}
void brainfuck() {
  cin >> pos >> n >> m;
  for (i = m + ((n - m) % 50);; i += 50) {
    rec((i / 50) % 475, 1);
    if (a && i <= n) {
      cout << "0";
      return;
    } else if (a) {
      a = (i - n) / 100;
      if ((i - n) % 100) a++;
      cout << a;
      return;
    }
  }
}
void rec(int idx, int x) {
  if (idx + 26 == pos) {
    a = 1;
    return;
  }
  if (x > 25) return;
  rec(((idx * 96) + 42) % 475, x + 1);
}
