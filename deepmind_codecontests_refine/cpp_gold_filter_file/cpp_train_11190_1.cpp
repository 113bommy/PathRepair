#include <bits/stdc++.h>
using namespace std;
int ary[300];
int n, w;
void mabna(int x, int m) {
  int temp = 0;
  while (x) {
    ary[temp] = x % m;
    x /= m;
    temp++;
  }
}
int main() {
  cin >> w >> n;
  mabna(n, w);
  if (w == 2) {
    for (int i = 101; i < 280; i++)
      if (ary[i]) {
        cout << "NO" << endl;
        return 0;
      }
    cout << "YES" << endl;
    return 0;
  }
  int temp = 0;
  for (int i = 0; i < 101; i++) {
    if (ary[i] == 1 || ary[i] == 0 || ary[i] == w || ary[i] == w - 1) {
      if (ary[i] == w - 1) {
        ary[i] = 0;
        ary[i + 1]++;
      }
      if (ary[i] == w) {
        ary[i] = 0;
        ary[i + 1]++;
      }
    } else {
      cout << "NO" << endl;
      return 0;
    }
  }
  for (int i = 101; i < 280; i++)
    if (ary[i]) {
      cout << "NO" << endl;
      return 0;
    }
  cout << "YES" << endl;
  return 0;
}
