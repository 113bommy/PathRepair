#include <bits/stdc++.h>
using namespace std;
int main() {
  string str, st;
  int n, cnt = 0, a = 0;
  cin >> n;
  cin >> str;
  cin >> st;
  for (int i = 0; i < n; i++) {
    str[i] = str[i] - '0';
  }
  for (int j = 0; j < n; j++) {
    st[j] = st[j] - '0';
  }
  for (int i = 0; i < n; i++) {
    if (abs(str[i] - st[i] < 5))
      cnt += abs(str[i] - st[i]);
    else {
      cnt += (10 - abs(str[i] - str[i]));
    }
  }
  cout << cnt << endl;
  return 0;
}
