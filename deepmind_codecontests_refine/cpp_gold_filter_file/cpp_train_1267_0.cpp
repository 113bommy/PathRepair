#include <bits/stdc++.h>
using namespace std;
const int N = 1e3;
map<char, int> mp, m1;
map<string, int> m2;
int used[N][N];
int use[100000];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int a, b, c;
  cin >> a >> b >> c;
  int x[a];
  for (int i = 0; i < a; i++) cin >> x[i];
  if (a == 1) return cout << 1, 0;
  for (int i = 0; i < a; i++) {
    long long cnt = 0, ans = 0;
    for (int j = 0; j < c; j++) {
      if (i + j < a) {
        if (x[i + j + 1] > x[i])
          cnt++;
        else {
          cnt = 0;
          break;
        }
      } else
        cnt++;
    }
    for (int j = 0; j < b; j++) {
      if (i - j - 1 > 0) {
        if (x[i] < x[i - j - 1])
          ans++;
        else {
          ans = 0;
          break;
        }
      } else
        ans++;
    }
    if (cnt == c and ans == b) return cout << i + 1 << "\n", 0;
  }
}
