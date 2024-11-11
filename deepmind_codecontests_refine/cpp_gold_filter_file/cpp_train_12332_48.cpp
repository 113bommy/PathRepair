#include <bits/stdc++.h>
using namespace std;
int turn(string s) {
  if (s == "S") return 0;
  if (s == "M") return 1;
  if (s == "L") return 2;
  if (s == "XL") return 3;
  if (s == "XXL") return 4;
}
int main() {
  int a[5];
  string t[5] = {"S", "M", "L", "XL", "XXL"};
  for (int i = 0; i < 5; i++) {
    cin >> a[i];
  }
  int k;
  cin >> k;
  for (int i = 0; i < k; i++) {
    string s;
    cin >> s;
    int cnt = turn(s);
    for (int j = 0; j < 5; j++) {
      if (cnt + j < 5 && a[cnt + j] > 0) {
        a[cnt + j]--;
        cout << t[cnt + j] << endl;
        break;
      }
      if (cnt - j >= 0 && a[cnt - j] > 0) {
        a[cnt - j]--;
        cout << t[cnt - j] << endl;
        break;
      }
    }
  }
  return 0;
}
