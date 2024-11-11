#include <bits/stdc++.h>
using namespace std;
string s;
int arr[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
pair<int, int> f(int i) {
  if (i - 6 >= 0 && s[i - 4] == '-' && s[i - 1] == '-' && s[i - 3] >= '0' &&
      s[i - 3] <= '9' && s[i - 2] >= '0' && s[i - 2] <= '9' &&
      s[i - 6] >= '0' && s[i - 6] <= '9' && s[i - 5] >= '0' &&
      s[i - 5] <= '9') {
    int x = (s[i - 3] - '0') * 10 + (s[i - 2] - '0');
    if (x > 0 && x <= 12) {
      int d = (s[i - 6] - '0') * 10 + (s[i - 5] - '0');
      if (d > 0 && d <= arr[x - 1]) return make_pair(d, x);
    }
  }
  return make_pair(-1, -1);
}
int main() {
  map<string, int> M;
  cin >> s;
  int v;
  int d = 0;
  string ans = "";
  for (int i = 0; i < s.size(); i++) {
    if (i + 3 < s.size() && s[i] == '2' && s[i + 1] == '0' && s[i + 2] == '1' &&
        (s[i + 3] >= '3' && s[i + 3] <= '5')) {
      pair<int, int> p = f(i);
      if (p.first != -1) {
        string a = "";
        for (int j = i - 6; j < i + 4; j++) a += s[j];
        if (M.count(a) == 0) {
          M[a] = 1;
          if (1 > d) {
            d = 1;
            ans = a;
          }
        } else {
          M[a]++;
          int t = M[a];
          if (t > d) {
            d = t;
            ans = a;
          }
        }
      }
    }
  }
  cout << ans;
  return 0;
}
