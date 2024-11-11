#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int y;
  cin >> y;
  int t = log10(y) + 1;
  if (t % 2 == 1) {
    int u = t + 1;
    for (int i = 0; i < (u / 2); i++) {
      cout << 4;
    }
    for (int i = 0; i < (u / 2); i++) {
      cout << 7;
    }
    cout << "\n";
  } else {
    long long int tx = 0;
    for (int i = 0; i < (t / 2); i++) {
      tx = (tx * 10) + 7;
    }
    for (int i = 0; i < (t / 2); i++) {
      tx = (tx * 10) + 4;
    }
    if (tx < y) {
      int u = t + 2;
      for (int i = 0; i < (u / 2); i++) {
        cout << 4;
      }
      for (int i = 0; i < (u / 2); i++) {
        cout << 7;
      }
    } else {
      int ar[11];
      for (int i = 0; i < (t / 2); i++) {
        ar[i] = 4;
      }
      for (int i = t / 2; i < t; i++) {
        ar[i] = 7;
      }
      long long p = y;
      long long mn = 0;
      for (int i = 0; i < t; i++) {
        mn = (mn * 10) + ar[i];
      }
      if (mn >= p) {
        cout << mn << "\n";
      } else {
        while (next_permutation(ar, ar + t)) {
          long long hm = 0;
          for (int i = 0; i < t; i++) {
            hm = (hm * 10) + ar[i];
          }
          if (p <= hm) {
            cout << hm << "\n";
            break;
          }
        }
      }
    }
  }
}
