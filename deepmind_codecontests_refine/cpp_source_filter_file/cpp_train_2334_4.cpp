#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int k;
  cin >> k;
  int count[9];
  memset(count, 0, sizeof(count));
  for (int i = 0; i < 4; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < 4; j++) {
      count[int(s[j]) - '0']++;
    }
  }
  bool flag = true;
  for (int i = 0; i < 9; i++) {
    if (count[i] > 2 * k) {
      flag = false;
      break;
    }
  }
  if (flag == true) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
