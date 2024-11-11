#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  while (cin >> n >> k) {
    string in;
    cin >> in;
    int last = 0;
    while (0 <= k && last + 1 < n) {
      while (last + 1 < n) {
        if (last + 2 < n && last % 2 == 0 && in[last] == '4' &&
            in[last + 1] == '7' && in[last + 2] == '7') {
          if (k % 2 != 0) in[last + 1] = '4';
          k = 0;
          break;
        } else if (last + 2 < n && last % 2 == 0 && in[last] == '4' &&
                   in[last + 1] == '4' && in[last + 2] == '7') {
          if (k % 2 == 1) in[last + 1] = '7';
          k = 0;
          break;
        } else if (last + 1 < n && in[last] == '4' && in[last + 1] == '7') {
          if (last % 2 == 0)
            in[last + 1] = '4';
          else
            in[last] = '7';
          break;
        } else
          last++;
      }
      k--;
    }
    cout << in << endl;
  }
}
