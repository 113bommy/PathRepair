#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, -1, 1, 0, -1, 1, 1, -1};
int dy[] = {-1, 0, 0, 1, -1, 1, -1, 1};
bool valid(int x, int y) {
  if (x < 0 || y < 0 || x >= 3 || y >= 3) return 0;
  return 1;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> dd;
  vector<int> ff;
  bool ans = 0;
  int ans1 = 0;
  int ans2 = 0;
  int ch = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    dd.push_back(x);
    ans1 += x;
  }
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    ff.push_back(x);
    ans2 += x;
  }
  for (int i = 0; i < n; i++) {
    if (dd[i] == 1 and ff[i] == 0) {
      ans = 1;
    }
  }
  if (ans == 1) {
    if (ans1 > ans2) {
      cout << 0;
    } else {
      ch = 1;
      int j = 0;
      while (ans1 <= ans2) {
        if (dd[j] == 1) {
          ans1++;
          if (ff[j] == 1) {
            ans2++;
          }
        }
        j++;
        if (j == n) {
          j = 0;
          ch++;
        }
      }
      cout << ch + 1;
    }
  } else {
    cout << -1;
  }
  return 0;
}
