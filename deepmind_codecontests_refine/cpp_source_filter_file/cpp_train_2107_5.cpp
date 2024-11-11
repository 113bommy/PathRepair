#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int ar[n];
    int colors[n];
    colors[0] = 1;
    for (int i = 0; i < n; i++) {
      cin >> ar[i];
    }
    int mxcolors = 1;
    int last = -1;
    int rot = 1;
    for (int i = 0; i < n; i++) {
      if (i == n - 1) {
        if (ar[i] == ar[0]) {
          goto done;
        } else {
          if (colors[i] != colors[0])
            goto done;
          else {
            if (last == -1) {
              colors[i] = 3;
              mxcolors = 3;
              goto done;
            } else {
              for (int j = last; j < n; j++) {
                colors[j] = 2 - (colors[j] + 1) % 2;
              }
              goto done;
            }
          }
        }
      }
      if (ar[i] == ar[i + 1]) {
        last = ar[i + 1];
        colors[i + 1] = colors[i];
      } else {
        mxcolors = 2;
        rot++;
        colors[i + 1] = 2 - (rot % 2);
      }
    }
  done:;
    cout << mxcolors << "\n";
    for (auto i : colors) cout << i << " ";
    cout << "\n";
  }
}
