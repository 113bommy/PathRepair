#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000;
int n, m, c;
int sheets[MAXN];
bool isDone() {
  bool done = true;
  for (int i = 0; i < n; i++)
    if (sheets[i] == 0) {
      done = false;
      break;
    }
  return done;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m >> c;
  for (int _m = 0; _m < m; _m++) {
    int i, inp;
    cin >> inp;
    if (inp <= c / 2) {
      for (i = 0; i < n; i++)
        if (sheets[i] == 0 || sheets[i] < inp) {
          sheets[i] = inp;
          break;
        }
    } else {
      for (i = n - 1; i >= 0; i--)
        if (sheets[i] == 0 || sheets[i] > inp) {
          sheets[i] = inp;
          break;
        }
    }
    cout << i + 1 << '\n';
    cout.flush();
    if (isDone()) break;
  }
  return 0;
}
