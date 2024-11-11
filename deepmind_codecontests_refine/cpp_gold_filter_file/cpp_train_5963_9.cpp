#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int N = 305;
int in[N][N], most[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int x;
      cin >> x;
      in[i][x] = j;
    }
  }
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    most[x] = i;
  }
  for (int i = 1; i <= n; i++) {
    int happy = N, card = -1;
    int chosen = -1;
    for (int avail = 1; avail <= n; avail++) {
      if (avail == i) continue;
      if (chosen == -1)
        chosen = avail;
      else if (most[avail] < most[chosen])
        chosen = avail;
      if (in[i][chosen] < happy) {
        happy = in[i][chosen];
        card = chosen;
      }
    }
    cout << card << ' ';
  }
}
