#include <bits/stdc++.h>
using namespace std;
const int Max = 2e6 + 10;
const int Mod = 1e9 + 7;
const long long int Inf = 1LL << 62;
struct Node {
  int x1, y1, x2, y2;
} ar[Max];
int c[Max];
int r[Max];
int rev[Max];
map<int, map<int, int>> mp;
int main() {
  int n;
  scanf("%d", &n);
  multiset<int> XL, YL, XR, YR;
  for (int i = 1; i <= n; i++) {
    scanf("%d %d %d %d", &ar[i].x1, &ar[i].y1, &ar[i].x2, &ar[i].y2);
    XL.insert(ar[i].x1);
    YL.insert(ar[i].y1);
    XR.insert(ar[i].x2);
    YR.insert(ar[i].y2);
  }
  for (int i = 1; i <= n; i++) {
    XL.erase(XL.find(ar[i].x1));
    YL.erase(YL.find(ar[i].y1));
    XR.erase(XR.find(ar[i].x2));
    YR.erase(YR.find(ar[i].y2));
    int xL = *XL.rbegin();
    int xR = *XR.begin();
    int yL = *YL.rbegin();
    int yR = *YR.begin();
    XL.insert(ar[i].x1);
    YL.insert(ar[i].y1);
    XR.insert(ar[i].x2);
    YR.insert(ar[i].y2);
    if (xL > xR) {
      continue;
    }
    if (yL > yR) {
      continue;
    }
    printf("%d %d\n", xR, yR);
    return 0;
  }
  return 0;
}
