#include <bits/stdc++.h>
using namespace std;
long long int n[110000], k[110000], d1[110000], d2[110000];
int main() {
  int t = 0;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cin >> n[i] >> k[i] >> d1[i] >> d2[i];
  }
  for (int i = 1; i <= t; i++) {
    int ans = 0;
    long long int w1, w2, w3;
    if (n[i] % 3 != 0) {
      cout << "no" << endl;
      continue;
    }
    w1 = 0;
    w2 = d1[i];
    w3 = d1[i] + d2[i];
    if (w1 >= 0 && w2 >= 0 && w3 >= 0 && (k[i] - w1 - w2 - w3 >= 0) &&
        ((k[i] - w1 - w2 - w3) % 3 == 0) &&
        (w1 + (k[i] - w1 - w2 - w3) / 3 <= n[i] / 3) &&
        (w2 + (k[i] - w1 - w2 - w3) / 3 <= n[i] / 3) &&
        (w3 + (k[i] - w1 - w2 - w3) / 3 <= n[i] / 3)) {
      ans = 1;
    }
    w1 = 0;
    w2 = d1[i];
    w3 = d1[i] - d2[i];
    if (w1 >= 0 && w2 >= 0 && w3 >= 0 && (k[i] - w1 - w2 - w3 >= 0) &&
        ((k[i] - w1 - w2 - w3) % 3 == 0) &&
        (w1 + (k[i] - w1 - w2 - w3) / 3 <= n[i] / 3) &&
        (w2 + (k[i] - w1 - w2 - w3) / 3 <= n[i] / 3) &&
        (w3 + (k[i] - w1 - w2 - w3) / 3 <= n[i] / 3)) {
      ans = 1;
    }
    w1 = d1[i];
    w2 = 0;
    w3 = d2[i];
    if (w1 >= 0 && w2 >= 0 && w3 >= 0 && (k[i] - w1 - w2 - w3 >= 0) &&
        ((k[i] - w1 - w2 - w3) % 3 == 0) &&
        (w1 + (k[i] - w1 - w2 - w3) / 3 <= n[i] / 3) &&
        (w2 + (k[i] - w1 - w2 - w3) / 3 <= n[i] / 3) &&
        (w3 + (k[i] - w1 - w2 - w3) / 3 <= n[i] / 3)) {
      ans = 1;
    }
    w1 = d2[i] - d1[i];
    w2 = d2[i];
    w3 = 0;
    if (w1 >= 0 && w2 >= 0 && w3 >= 0 && (k[i] - w1 - w2 - w3 >= 0) &&
        ((k[i] - w1 - w2 - w3) % 3 == 0) &&
        (w1 + (k[i] - w1 - w2 - w3) / 3 <= n[i] / 3) &&
        (w2 + (k[i] - w1 - w2 - w3) / 3 <= n[i] / 3) &&
        (w3 + (k[i] - w1 - w2 - w3) / 3 <= n[i] / 3)) {
      ans = 1;
    }
    w1 = d2[i] + d1[i];
    w2 = d2[i];
    w3 = 0;
    if (w1 >= 0 && w2 >= 0 && w3 >= 0 && (k[i] - w1 - w2 - w3 >= 0) &&
        ((k[i] - w1 - w2 - w3) % 3 == 0) &&
        (w1 + (k[i] - w1 - w2 - w3) / 3 <= n[i] / 3) &&
        (w2 + (k[i] - w1 - w2 - w3) / 3 <= n[i] / 3) &&
        (w3 + (k[i] - w1 - w2 - w3) / 3 <= n[i] / 3)) {
      ans = 1;
    }
    if (ans == 1)
      cout << "yes" << endl;
    else
      cout << "no" << endl;
  }
}
