#include <bits/stdc++.h>
using namespace std;
long long int ans = 0;
vector<long long int> disputed;
vector<long long int> berland;
vector<long long int> byteland;
void add() {
  if (disputed.size() == 1) {
    if (berland.size()) ans += disputed[0] - berland[0];
    if (byteland.size()) ans += disputed[0] - byteland[0];
  } else {
    int n = disputed.size();
    int bn = berland.size();
    int rn = byteland.size();
    long long int last = disputed[n - 1] - disputed[n - 2];
    long long int last_2 = 2 * last;
    if (bn) {
      long long int mx =
          max(disputed[n - 1] - berland[bn - 1], berland[0] - disputed[n - 2]);
      for (int i = 0; i < bn - 1; i++) {
        mx = max(mx, berland[i + 1] - berland[i]);
      }
      last += disputed[n - 1] - disputed[n - 2] - mx;
    }
    if (rn) {
      long long int mx = max(disputed[n - 1] - byteland[rn - 1],
                             byteland[0] - disputed[n - 2]);
      for (int i = 0; i < rn - 1; i++) {
        mx = max(mx, byteland[i + 1] - byteland[i]);
      }
      last += disputed[n - 1] - disputed[n - 2] - mx;
    }
    ans += min(last, last_2);
  }
  berland.clear();
  byteland.clear();
}
void complete() {
  if (disputed.size() == 0) {
    if (byteland.size()) ans += byteland.back() - byteland.front();
    if (berland.size()) ans += berland.back() - berland.front();
  } else {
    if (byteland.size()) ans += byteland.back() - disputed.back();
    if (berland.size()) ans += berland.back() - disputed.back();
  }
}
int main() {
  long long int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int pos;
    char c;
    cin >> pos >> c;
    if (c == 'P') {
      disputed.push_back(pos);
      add();
    } else if (c == 'R') {
      berland.push_back(pos);
    } else {
      byteland.push_back(pos);
    }
  }
  complete();
  cout << ans;
}
