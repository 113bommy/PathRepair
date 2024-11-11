#include <bits/stdc++.h>
using namespace std;
int query(int x, int y, int X, int Y) {
  cout << "? " << x << " " << y << " " << X << " " << Y << endl;
  cout.flush();
  int res;
  cin >> res;
  return res;
}
int n;
int lb, rb, llb, rrb, tb, ttb, bb, bbb;
void end(int x1, int y1, int x2, int y2, int X1, int Y1, int X2, int Y2) {
  cout << "!" << x1 << " " << y1 << " " << x2 << " " << y2 << " " << X1 << " "
       << Y1 << " " << X2 << " " << Y2 << endl;
  exit(0);
}
int main() {
  cin >> n;
  for (int jump = (1 << 16); jump > 0; (jump >>= 1)) {
    if (rrb + jump <= n)
      if (query(1, 1, rrb + jump, n) < 2) rrb += jump;
  }
  rrb++;
  for (int jump = (1 << 16); jump > 0; (jump >>= 1)) {
    if (rb + jump <= rrb)
      if (query(1, 1, rb + jump, n) < 1) rb += jump;
  }
  rb++;
  llb = rrb + 1;
  for (int jump = (1 << 16); jump > 0; (jump >>= 1)) {
    if (llb - jump > 0)
      if (query(llb - jump, 1, rrb, n) < 2) llb -= jump;
  }
  llb--;
  lb = rrb + 1;
  for (int jump = (1 << 16); jump > 0; (jump >>= 1)) {
    if (lb - jump)
      if (query(lb - jump, 1, rrb, n) < 1) lb -= jump;
  }
  lb--;
  for (int jump = (1 << 16); jump > 0; (jump >>= 1)) {
    if (ttb + jump <= n)
      if (query(llb, 1, rrb, ttb + jump) < 2) ttb += jump;
  }
  ttb++;
  for (int jump = (1 << 16); jump > 0; (jump >>= 1)) {
    if (tb + jump <= ttb)
      if (query(llb, 1, rrb, tb + jump) < 1) tb += jump;
  }
  tb++;
  bbb = ttb + 1;
  for (int jump = (1 << 16); jump > 0; (jump >>= 1)) {
    if (bbb - jump > 0)
      if (query(llb, bbb - jump, rrb, ttb) < 2) bbb -= jump;
  }
  bbb--;
  bb = ttb + 1;
  for (int jump = (1 << 16); jump > 0; (jump >>= 1)) {
    if (bb - jump)
      if (query(llb, bb - jump, rrb, ttb) < 1) bb -= jump;
  }
  bb--;
  if (query(llb, bbb, rb, tb) == 1 && query(lb, bb, rrb, ttb) == 1)
    end(llb, bbb, rb, tb, lb, bb, rrb, ttb);
  if (query(lb, bbb, rrb, tb) == 1 && query(llb, bb, rb, ttb) == 1)
    end(lb, bbb, rrb, tb, llb, bb, rb, ttb);
  if (query(llb, bbb, rrb, tb) == 1 && query(lb, bb, rb, ttb) == 1)
    end(llb, bbb, rrb, tb, lb, bb, rb, ttb);
  if (query(llb, bb, rb, ttb) == 1 && query(lb, bbb, rrb, tb) == 1)
    end(llb, bb, rb, ttb, lb, bbb, rrb, tb);
  if (query(lb, bb, rrb, ttb) == 1 && query(llb, bbb, rb, tb) == 1)
    end(lb, bb, rrb, ttb, llb, bbb, rb, tb);
  if (query(llb, bb, rrb, ttb) == 1 && query(lb, bbb, rb, tb) == 1)
    end(llb, bb, rrb, ttb, lb, bbb, rb, tb);
  if (query(llb, bbb, rb, ttb) == 1 && query(lb, bb, rrb, tb) == 1)
    end(llb, bbb, rb, ttb, lb, bb, rrb, tb);
  if (query(lb, bbb, rrb, ttb) == 1 && query(llb, bb, rb, tb) == 1)
    end(lb, bbb, rrb, ttb, llb, bb, rb, tb);
  if (query(llb, bbb, rrb, ttb) == 1 && query(lb, bb, rb, tb) == 1)
    end(llb, bbb, rrb, ttb, lb, bb, rb, tb);
  return 0;
}
