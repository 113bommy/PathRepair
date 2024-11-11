#include <bits/stdc++.h>
using namespace std;
struct pi {
  int first, mid, second;
  void make(int x, int y, int z) {
    first = x;
    mid = y;
    second = z;
  }
};
const int N = 100 + 50;
int D;
int t, n;
vector<int> maxi, mini;
int main() {
  cin >> t;
  while (t--) {
    mini.clear();
    maxi.clear();
    cin >> n;
    for (int i = 1; i <= n / 2; ++i) {
      char c;
      cout << "? " << 2 * i - 1 << ' ' << i * 2 << '\n';
      cin >> c;
      if (c == '>') {
        maxi.push_back(2 * i - 1);
        mini.push_back(2 * i);
      } else {
        maxi.push_back(2 * i);
        mini.push_back(2 * i - 1);
      }
    }
    if (n % 2) {
      maxi.push_back(n);
      mini.push_back(n);
    }
    while (maxi.size() > 1) {
      char c;
      int x = maxi[maxi.size() - 1], y = maxi[maxi.size() - 2];
      cout << "? " << x << ' ' << y << '\n';
      maxi.pop_back();
      maxi.pop_back();
      cin >> c;
      if (c == '>') {
        maxi.push_back(x);
      } else {
        maxi.push_back(y);
      }
    }
    while (mini.size() > 1) {
      char c;
      int x = mini[mini.size() - 1], y = mini[mini.size() - 2];
      cout << "? " << x << ' ' << y << '\n';
      mini.pop_back();
      mini.pop_back();
      cin >> c;
      if (c == '>') {
        mini.push_back(x);
      } else {
        mini.push_back(y);
      }
    }
    cout << "! " << mini[0] << ' ' << maxi[0] << '\n';
  }
  return 0;
}
