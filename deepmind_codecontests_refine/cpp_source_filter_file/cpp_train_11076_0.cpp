#include <bits/stdc++.h>
using namespace std;
int Count(string str) {
  long long cnt = 0;
  long long res = 0;
  for (int i = 0; i < str.size(); i++) {
    if (str.substr(i, 5) == "heavy") cnt++;
    if (str.substr(i, 5) == "metal") res += cnt;
  }
  return res;
}
int main() {
  string str;
  cin >> str;
  long long ans = Count(str);
  cout << ans << endl;
  return 0;
}
