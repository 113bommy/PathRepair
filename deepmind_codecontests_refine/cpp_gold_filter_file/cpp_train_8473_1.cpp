#include <bits/stdc++.h>
using namespace std;
int main() {
  long cnt[10];
  int b, n;
  for (int i = 0; i <= 7; i++) {
    cnt[i] = 0;
  }
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> b;
    cnt[b]++;
  }
  if (((cnt[6] + cnt[4]) != cnt[1]) || ((cnt[2] + cnt[3]) != cnt[1]) ||
      cnt[5] != 0 || cnt[3] > cnt[6] || cnt[7] != 0) {
    cout << -1;
  } else {
    for (int i = 0; i < cnt[1]; i++) {
      cout << "1 ";
      if (cnt[3] > 0) {
        cout << "3 ";
        cnt[3]--;
      } else {
        cout << "2 ";
        cnt[2]--;
      }
      if (cnt[6] > 0) {
        cout << "6" << endl;
        cnt[6]--;
      } else {
        cout << "4" << endl;
        cnt[4]--;
      }
    }
  }
  return 0;
}
