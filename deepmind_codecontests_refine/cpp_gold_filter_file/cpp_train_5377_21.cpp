#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int res = 0;
  int cnt = 1;
  while (cnt != (n / 2) + 1) {
    int copy = n;
    copy -= cnt;
    if (copy % cnt == 0) {
      res++;
    }
    cnt++;
  }
  cout << res;
}
