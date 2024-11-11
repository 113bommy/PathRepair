#include <bits/stdc++.h>
using namespace std;
void input() {
  freopen("input.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
}
struct Task {
  int x;
  int y;
};
bool comparison(Task k1, Task k2) {
  if (k1.x == k2.x)
    return k1.y < k2.y;
  else
    return k1.x < k2.x;
}
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    Task arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i].x >> arr[i].y;
    sort(arr, arr + n, comparison);
    int asi = 0, asy = 0, f = 0;
    string st;
    for (int i = 0; i < n; i++) {
      int dx = arr[i].x;
      int dy = arr[i].y;
      if (dx < asi || dy < asy) {
        cout << "NO"
             << "\n";
        f = 1;
        break;
      } else {
        int ulagbe = dx - asi;
        int rlagbe = dy - asy;
        for (int i = 0; i < ulagbe; i++) st += 'R';
        for (int i = 0; i < rlagbe; i++) st += 'U';
        asi = dx;
        asy = dy;
      }
    }
    if (f == 0) {
      cout << "YES"
           << "\n";
      cout << st << "\n";
    }
  }
}
