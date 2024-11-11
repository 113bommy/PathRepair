#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> ans(n);
    vector<int> color(n / 3);
    int white = 0, black = 0;
    int w = -1, b = -1;
    for (int i = 0; i < n; i += 3) {
      int res;
      cout << "? " << i + 1 << " " << i + 2 << " " << i + 3 << endl;
      cin >> res;
      color[i / 3] = res;
      if (res == 1)
        white = i;
      else
        black = i;
    }
    int res, res1;
    cout << "? " << white + 1 << " " << white + 2 << " " << black + 1 << endl;
    cin >> res;
    cout << "? " << white + 1 << " " << white + 2 << " " << black + 2 << endl;
    cin >> res1;
    if (res == -1 || res1 == -1) return 0;
    if (res == 1 && res1 == 1) {
      w = white;
      cout << "? " << w + 1 << " " << black + 1 << " " << black + 2 << endl;
      cin >> res;
      cout << "? " << w + 1 << " " << black + 3 << " " << black + 2 << endl;
      cin >> res1;
      if (res == -1 || res1 == -1) return 0;
      if (res == 1 && res1 == 1) {
        ans[black] = ans[black + 2] = 1;
        b = black;
      } else if (res == 1 && res1 == 0) {
        ans[black + 1] = ans[black + 2] = 1;
        b = black + 1;
      } else if (res == 0 && res1 == 1) {
        ans[black] = ans[black + 1] = 1;
        b = black;
      } else {
        ans[black] = ans[black + 1] = ans[black + 2] = 1;
        b = black;
      }
      cout << "? " << w + 1 << " " << b + 1 << " " << white + 3 << endl;
      cin >> res;
      if (res == -1 || res1 == -1) return 0;
      if (res == 0) ans[white + 2] = 1;
    } else {
      cout << "? " << white + 3 << " " << white + 2 << " " << black + 1 << endl;
      cin >> res;
      cout << "? " << white + 3 << " " << white + 2 << " " << black + 2 << endl;
      cin >> res1;
      if (res == -1 || res1 == -1) return 0;
      if (res == 1 && res1 == 1) {
        w = white + 1;
        ans[white] = 1;
      } else {
        w = white;
        ans[white + 1] = 1;
      }
      cout << "? " << w + 1 << " " << black + 1 << " " << black + 2 << endl;
      cin >> res;
      cout << "? " << w + 1 << " " << black + 3 << " " << black + 2 << endl;
      cin >> res1;
      if (res == -1 || res1 == -1) return 0;
      if (res == 1 && res1 == 1) {
        ans[black] = ans[black + 2] = 1;
        b = black;
      } else if (res == 1 && res1 == 0) {
        ans[black + 1] = ans[black + 2] = 1;
        b = black + 1;
      } else if (res == 0 && res1 == 1) {
        ans[black] = ans[black + 1] = 1;
        b = black;
      } else {
        ans[black] = ans[black + 1] = ans[black + 2] = 1;
        b = black;
      }
      if (res == -1 || res1 == -1) return 0;
    }
    for (int i = 0; i < n; i += 3) {
      if (white == i || black == i) continue;
      int res, res1;
      if (color[i / 3]) {
        cout << "? " << b + 1 << " " << i + 2 << " " << i + 3 << endl;
        cin >> res;
        cout << "? " << b + 1 << " " << i + 2 << " " << i + 1 << endl;
        cin >> res1;
        if (res == -1 || res1 == -1) return 0;
        if (res == 0 && res1 == 0) {
          ans[i + 1] = 1;
        } else if (res == 0 && res1 == 1) {
          ans[i + 2] = 1;
        } else if (res == 1 && res1 == 0) {
          ans[i] = 1;
        }
      } else {
        cout << "? " << w + 1 << " " << i + 2 << " " << i + 3 << endl;
        cin >> res;
        cout << "? " << w + 1 << " " << i + 2 << " " << i + 1 << endl;
        cin >> res1;
        if (res == -1 || res1 == -1) return 0;
        if (res == 1 && res1 == 1) {
          ans[i] = ans[i + 2] = 1;
        } else if (res == 0 && res1 == 1) {
          ans[i + 1] = ans[i + 2] = 1;
        } else if (res == 1 && res1 == 0) {
          ans[i] = ans[i + 1] = 1;
        } else
          ans[i] = ans[i + 1] = ans[i + 2];
      }
    }
    vector<int> out;
    for (int i = 0; i < n; i++) {
      if (ans[i]) out.push_back(i + 1);
    }
    cout << "! " << out.size();
    for (int i : out) cout << " " << i;
    cout << endl;
  }
  return 0;
}
