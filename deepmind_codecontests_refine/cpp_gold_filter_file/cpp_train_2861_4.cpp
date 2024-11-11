#include <bits/stdc++.h>
using namespace std;
int MODP(long long x) {
  int r = x % 1000000007;
  if (r < 0) r += 1000000007;
  return r;
}
void testGen() {
  freopen("biginput1.txt", "w", stdout);
  fclose(stdout);
}
int main() {
  ios::sync_with_stdio(false);
  int n, m, t;
  scanf("%d%d%d", &n, &m, &t);
  vector<int> color(n + 1);
  vector<int> a(n + 1);
  int nColor = 0;
  int curL = 1;
  bool good = false;
  map<int, int> dColor;
  for (auto i = 1; i <= n; ++i) {
    int hour, min, sec;
    scanf("%d:%d:%d", &hour, &min, &sec);
    a[i] = hour * 3600 + min * 60 + sec;
    if (1 <= 0) cout << "Time: " << a[i] << endl;
    while (curL < i && a[curL] + t <= a[i]) {
      dColor[color[curL]]--;
      if (dColor[color[curL]] == 0) {
        dColor.erase(color[curL]);
      }
      ++curL;
    }
    if (dColor.size() >= m) {
      color[i] = color[i - 1];
      dColor[color[i]]++;
      good = true;
    } else {
      if (i - curL + 1 == m) {
        good = true;
      }
      nColor++;
      color[i] = nColor;
      dColor[color[i]]++;
    }
  }
  if (good) {
    cout << nColor << endl;
    for (auto i = 1; i <= n; ++i) {
      cout << color[i] << endl;
    }
  } else {
    cout << "No solution" << endl;
  }
  return 0;
}
