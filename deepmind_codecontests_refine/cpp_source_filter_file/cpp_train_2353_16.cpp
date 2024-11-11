#include <bits/stdc++.h>
using namespace std;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int main() {
  const int MAX = 201000;
  int n, k, q;
  cin >> n >> k >> q;
  int range[MAX] = {};
  for (int i = 0; i < n; i++) {
    int r, l;
    cin >> r >> l;
    range[r]++;
    range[l + 1]--;
  }
  for (int i = 1; i < MAX; i++) {
    range[i] = range[i - 1] + range[i];
  }
  int tes[202] = {};
  for (int i = 0; i <= 200; i++) {
    int test = 0;
    for (int j = i * 1000; j <= (i * 1000 + 999); j++) {
      if (range[j] >= k) {
        test++;
      }
    }
    tes[i] = test;
  }
  for (int i = 0; i < q; i++) {
    int a, b;
    cin >> a >> b;
    int cou = 0;
    if (b - a > 5000) {
      for (int i = (a / 1000 + 1); i <= (b / 1000); i++) {
        cou += tes[i];
      }
      for (int i = a; i <= ((a / 1000 + 1) * 1000 - 1); i++) {
        if (range[i] >= k) {
          cou++;
        }
      }
      for (int i = ((b / 1000) * 1000); i <= b; i++) {
        if (range[i] >= k) {
          cou++;
        }
      }
    } else {
      for (int i = a; i <= b; i++) {
        if (range[i] >= k) {
          cou++;
        }
      }
    }
    cout << cou << endl;
  }
  return 0;
}
