#include <bits/stdc++.h>
using namespace std;
using namespace std;
string second;
int d[400002], k = 0;
bool ans = true;
int main() {
  cin >> second;
  for (int i = 0; i < second.size(); i++) {
    if (second[i] == '.') d[k++] = i;
  }
  for (int i = 0; i < k - 1; i++) {
    if (d[i + 1] - d[i] - 1 > 11 || d[i + 1] - d[i] - 1 < 2) ans = false;
  }
  if (d[0] - 0 > 8 || d[0] - 0 <= 0) ans = false;
  if (second.size() - d[k - 1] - 1 > 3 || second.size() - d[k - 1] - 1 <= 0)
    ans = false;
  int j = 1;
  if (ans) {
    cout << "YES" << endl;
    for (int i = 0; i < d[0]; i++) {
      cout << second[i];
    }
    for (int i = d[0]; i < d[k - 1];) {
      cout << second[i] << second[i + 1];
      i += 2;
      while (d[j] - i - 1 >= 8) {
        cout << second[i];
        i++;
      }
      cout << endl;
      while (i < d[j]) {
        cout << second[i++];
      }
      j++;
    }
    for (int i = d[j - 1]; i < second.size(); i++) cout << second[i];
  } else
    cout << "NO" << endl;
  return 0;
}
