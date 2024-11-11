#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int count[10];
  for (int i = 0; i < 10; i++) count[i] = 0;
  for (int i = 0; i < n; i++) {
    int t = s[i] - '0';
    switch (t) {
      case 2:
        count[2]++;
        break;
      case 3:
        count[3]++;
        break;
      case 4:
        count[3]++, count[2] += 2;
        break;
      case 5:
        count[5]++;
        break;
      case 6:
        count[5]++, count[3]++;
        break;
      case 7:
        count[7]++;
        break;
      case 8:
        count[7]++, count[2] += 3;
        break;
      case 9:
        count[7]++, count[3] += 2, count[2] += 3;
        break;
      default:
        break;
    }
  }
  string r = "";
  for (int i = 9; i > 1; i--) {
    for (int j = 0; j < count[i]; j++) r += char(i + '0');
  }
  cout << r << endl;
  return 0;
}
