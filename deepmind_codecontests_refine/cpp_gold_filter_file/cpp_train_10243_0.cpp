#include <bits/stdc++.h>
using namespace std;
string a[2];
int br[2] = {0, 0};
int main() {
  cin >> a[0] >> a[1];
  for (int j = 0; j < 2; j++) {
    for (int i = 0; i < a[j].size(); i++) {
      if (a[j][i] == '1') {
        br[j]++;
      }
    }
  }
  if (br[1] > br[0] + br[0] % 2) {
    cout << "NO";
    return 0;
  } else {
    cout << "YES";
  }
  return 0;
}
