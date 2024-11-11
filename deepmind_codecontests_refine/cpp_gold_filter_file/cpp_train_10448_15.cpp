#include <bits/stdc++.h>
using namespace std;
int cnt[1001000];
int main() {
  int a, b, c, sum = 0, mul = 0;
  cin >> a >> b >> c;
  for (int i = 1; i <= 1000000; i++) {
    for (int j = 1; i * j <= 1000000; j++) {
      cnt[i * j]++;
    }
  }
  for (int i = 1; i <= a; i++) {
    for (int j = 1; j <= b; j++) {
      for (int k = 1; k <= c; k++) {
        mul = i * j * k;
        sum += cnt[mul];
      }
    }
  }
  cout << sum << endl;
  return 0;
}
