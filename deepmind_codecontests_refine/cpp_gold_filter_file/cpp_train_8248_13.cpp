#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int ar[n + 5];
    int mark[500000];
    memset(mark, 0, sizeof mark);
    for (int i = 0; i < n; i++) {
      cin >> ar[i];
      mark[ar[i]] = 1;
    }
    int minim = 999999;
    int cnt = 0;
    int flag = 0;
    for (int i = 1; i <= 1024; i++) {
      if (flag) break;
      cnt = 0;
      for (int j = 0; j < n; j++) {
        int p = ar[j] ^ i;
        if (mark[p]) {
          cnt++;
        }
      }
      if (cnt == n) {
        minim = min(minim, i);
      }
    }
    if (minim == 999999) {
      cout << "-1" << endl;
    } else {
      cout << minim << endl;
    }
  }
  return 0;
}
