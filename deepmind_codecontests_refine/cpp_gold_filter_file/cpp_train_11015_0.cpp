#include <bits/stdc++.h>
using namespace std;
int k, n, res;

int color(int r, int c) {
  int ret = 0;
  ret += n * (r & 1);
  ret += (c + r) % n;
  if(r & 1 && (c + r) % n >= n - res){
    ret -= n;
  }
  ret++;
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> k;
  if (k == 1) {
    cout << "1\n1" << '\n';
    return 0;
  }

  n = (k + 3) / 4 * 2;
  res = n * 2 - k;
  cout << n << '\n';
  for (int r = 0; r < n; r++) {
    for (int c = 0; c < n; c++) {
      cout << color(r, c);
      if (c==n-1){
        cout << '\n';
      } else {
        cout << ' ';
      }
    }
  }
  return 0;
}