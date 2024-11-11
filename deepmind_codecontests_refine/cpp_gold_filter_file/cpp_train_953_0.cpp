#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, I;
  cin >> n >> I;
  int data[400005];
  int la[400005], lai = 0, last = -1;
  for (int i = 0; i < n; i++) cin >> data[i];
  sort(data, data + n);
  int now = 0;
  for (int i = 0; i < n; i++) {
    if (data[i] != last) {
      la[lai++] = now;
      now = 1;
      last = data[i];
    } else {
      now++;
    }
  }
  la[lai] = now;
  I = 8 * I / n;
  if (I > 20) I = 20;
  long long range = 1 << I;
  if (range >= lai)
    cout << 0 << endl;
  else {
    for (int i = 2; i <= lai; i++) {
      la[i] += la[i - 1];
    }
    int ans = 0;
    for (long long i = range; i <= lai; i++) {
      if (la[i] - la[i - range] > ans) ans = la[i] - la[i - range];
    }
    cout << n - ans << endl;
  }
  return 0;
}
