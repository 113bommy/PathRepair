#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  char ch;
  int sum = 0;
  long long res = 1;
  string a;
  cin >> a;
  int len2 = a.size();
  for (int i = 1; i < len2; i++) {
    int t = a[i] - 48 + a[i - 1] - 48;
    if ((a[i] - 48 + a[i - 1] - 48) == 9) {
      int pos1 = i;
      int pos2 = i - 1;
      int len = 2;
      int j = i + 1;
      for (; j < len2; j++) {
        if (a[pos2] == a[j]) {
          pos2 = j;
          len++;
        } else {
          i = j - 1;
          break;
        }
        if (a[pos1] == a[j + 1] && j + 1 < len2) {
          pos1 = j + 1;
          len++;
          j = j + 1;
        } else {
          i = j;
          break;
        }
      }
      if (len % 2 != 0) {
        res *= (len - 2) * 2;
      }
    }
  }
  cout << res << endl;
  return 0;
}
