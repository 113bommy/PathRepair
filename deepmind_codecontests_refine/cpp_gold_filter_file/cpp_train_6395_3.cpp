#include <bits/stdc++.h>
using namespace std;
int main(int argc, const char* argv[]) {
  int ts;
  int n, p;
  cin >> ts;
  for (int tt = 0; tt < ts; tt++) {
    cin >> n >> p;
    int e[100][100];
    int s[100];
    memset(s, 0, sizeof(s));
    memset(e, 0, sizeof(e));
    for (int i = 0; i < n; i++) {
      for (int j = s[i]; j < 4; j++) {
        int t = i + 1;
        for (int k = i + 1; k < n; k++) {
          if (s[k] < s[t]) {
            t = k;
          }
        }
        if (s[t] == 4) {
          return -1;
        }
        e[i][t] = 1;
        s[i]++;
        s[t]++;
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (e[i][j]) {
          cout << i + 1 << ' ' << j + 1 << endl;
        } else if (p > 0) {
          cout << i + 1 << ' ' << j + 1 << endl;
          p--;
        }
      }
    }
  }
}
