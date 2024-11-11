#include <bits/stdc++.h>
using namespace std;
struct mnmx {
  int mn = 1, mx = 1;
};
int pp[55];
int question(int x, int y, bool q) {
  char c;
  cout << "? " << x << " " << y << endl;
  fflush(stdout);
  cin >> c;
  if (c == '>' && q == 1) return x;
  if (c == '<' && q == 1) return y;
  if (c == '=' && q == 1) return x;
  if (c == '>' && q == 0) return y;
  if (c == '<' && q == 0) return x;
  if (c == '=' && q == 0) return x;
  return -1;
}
mnmx Search(int st, int dr) {
  mnmx p, p1, p2;
  int mid = (st + dr) / 2, i = mid;
  while (pp[i - st + 1] == 0) {
    if (i < 50) i++;
    if (pp[i - st + 1] == 1) mid = i;
  }
  if (st == dr) {
    p.mn = st;
    p.mx = st;
    return p;
  }
  if (st == dr - 1) {
    p.mn = question(st, dr, false);
    if (p.mn == st)
      p.mx = dr;
    else
      p.mx = st;
    return p;
  }
  p1 = Search(st, mid);
  p2 = Search(mid + 1, dr);
  p.mn = question(p1.mn, p2.mn, false);
  p.mx = question(p1.mx, p2.mx, true);
  return p;
}
int main() {
  int T, N, x = 1;
  pp[0] = 1;
  while (x <= 50) {
    pp[x] = 1;
    x *= 2;
  }
  cin >> T;
  while (T) {
    cin >> N;
    mnmx sol;
    sol = Search(1, N);
    cout << "! " << sol.mn << " " << sol.mx << "\n";
    fflush(stdout);
    T--;
  }
}
