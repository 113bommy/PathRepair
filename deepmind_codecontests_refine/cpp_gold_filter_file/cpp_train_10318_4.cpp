#include <bits/stdc++.h>
using namespace std;
int main() {
  int n = 0;
  cin >> n;
  int in[n];
  int count[101] = {0};
  for (int i = 0; i < n; i++) {
    cin >> in[i];
    count[in[i]]++;
  }
  int niceCount = 0;
  int gtTwoInd = -1;
  string res;
  for (int i = 0; i < n; i++) {
    if (count[in[i]] > 0) {
      if (count[in[i]] == 1) {
        niceCount++;
        if (niceCount % 2) {
          res += "A";
        } else {
          res += "B";
        }
      } else {
        if (count[in[i]] > 2) {
          gtTwoInd = i;
        }
        res += "A";
      }
    }
  }
  if (niceCount % 2) {
    if (gtTwoInd == -1) {
      cout << "NO" << endl;
    } else {
      res[gtTwoInd] = 'B';
      cout << "YES" << endl;
      cout << res << endl;
    }
  } else {
    cout << "YES" << endl;
    cout << res << endl;
  }
}
