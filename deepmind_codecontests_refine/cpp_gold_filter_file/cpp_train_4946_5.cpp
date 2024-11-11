#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:60777216")
using namespace std;
int n, k;
int x[111111];
int y[111111];
vector<int> X, Y;
int YL[222222];
int YR[222222];
int XL[222222];
int XR[222222];
int solveYL(int ypos) {
  if (YL[ypos] != -1) return YL[ypos];
  int num = 0;
  for (int i = (0); i < (n); i++)
    if (y[i] < Y[ypos]) num++;
  return YL[ypos] = num;
}
int solveYR(int ypos) {
  if (YR[ypos] != -1) return YR[ypos];
  int num = 0;
  for (int i = (0); i < (n); i++)
    if (y[i] > Y[ypos]) num++;
  return YR[ypos] = num;
}
int solveXL(int xpos) {
  if (XL[xpos] != -1) return XL[xpos];
  int num = 0;
  for (int i = (0); i < (n); i++)
    if (x[i] < X[xpos]) num++;
  return XL[xpos] = num;
}
int solveXR(int xpos) {
  if (XR[xpos] != -1) return XR[xpos];
  int num = 0;
  for (int i = (0); i < (n); i++)
    if (x[i] > X[xpos]) num++;
  return XR[xpos] = num;
}
map<pair<int, int>, int> M[2][2];
int solve(int xpos, int ypos, int dx, int dy) {
  if (M[dx][dy].count(pair<int, int>(xpos, ypos)))
    return M[dx][dy][pair<int, int>(xpos, ypos)];
  int num = 0;
  for (int i = (0); i < (n); i++) {
    if ((x[i] <= X[xpos]) && dx == 1) continue;
    if ((x[i] >= X[xpos]) && dx == 0) continue;
    if ((y[i] <= Y[ypos]) && dy == 1) continue;
    if ((y[i] >= Y[ypos]) && dy == 0) continue;
    num++;
  }
  return M[dx][dy][pair<int, int>(xpos, ypos)] = num;
}
int main() {
  memset(YL, -1, sizeof YL);
  memset(XL, -1, sizeof XL);
  memset(YR, -1, sizeof YR);
  memset(XR, -1, sizeof XR);
  cin >> n >> k;
  for (int i = (0); i < (n); i++) {
    int x1, y1, x2, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    int xx = (x1 + x2);
    int yy = (y1 + y2);
    x[i] = xx;
    y[i] = yy;
    X.push_back(xx);
    Y.push_back(yy);
  }
  long long best = 4e18;
  sort((X).begin(), (X).end()),
      (X).erase(unique((X).begin(), (X).end()), (X).end()),
      sort((Y).begin(), (Y).end()),
      (Y).erase(unique((Y).begin(), (Y).end()), (Y).end());
  for (int yl = 0; yl < Y.size(); yl++) {
    if (yl > k) break;
    for (int yr = Y.size() - 1; yr >= yl; yr--) {
      if (Y.size() - 1 - yr > k) break;
      for (int xl = 0; xl < X.size(); xl++) {
        if (xl > k) break;
        for (int xr = X.size() - 1; xr >= xl; xr--) {
          if (X.size() - 1 - xr > k) break;
          int num = solveYL(yl) + solveYR(yr) + solveXL(xl) + solveXR(xr);
          num -= solve(xl, yl, 0, 0);
          num -= solve(xl, yr, 0, 1);
          num -= solve(xr, yl, 1, 0);
          num -= solve(xr, yr, 1, 1);
          if (num <= k) {
            long long d1 = Y[yr] - Y[yl] + 0ll;
            long long d2 = X[xr] - X[xl] + 0ll;
            d1 = max(1ll, (d1 + 1) / 2);
            d2 = max(1ll, (d2 + 1) / 2);
            best = min(best, d1 * d2);
          }
        }
      }
    }
  }
  cout << best << endl;
  return 0;
}
