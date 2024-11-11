#include <bits/stdc++.h>
using namespace std;
long long a[2222222];
int cnt[111];
long long n, m, k, q, l, r;
int main() {
  cin >> n;
  for (int i = (0); i < (n); i++) cin >> a[i], cnt[a[i]]++;
  int frames = 0;
  for (int i = (1); i < (101); i++) {
    if (cnt[i] > 4) {
      frames += (cnt[i] / 4);
      frames = cnt[i] % 4;
    }
  }
  for (int i = (1); i < (101); i++) {
    for (int j = (1); j < (101); j++) {
      if (i == j) continue;
      if (cnt[i] >= 2 && cnt[j] >= 2) {
        frames++;
        cnt[i] -= 2;
        cnt[j] -= 2;
      }
    }
  }
  cout << frames << endl;
  return 0;
}
