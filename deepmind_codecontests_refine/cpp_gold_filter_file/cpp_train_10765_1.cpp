#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long x;
  cin >> x;
  vector<string> ans;
  if (x == 0) {
    cout << "O-|-OOOO";
  } else {
    while (x != 0) {
      long long temp = x % 10;
      string a;
      if (temp >= 5) {
        a += "-O|";
        temp -= 5;
      } else {
        a += "O-|";
      }
      for (long long i = 0; i < temp; i++) {
        a += 'O';
      }
      a += '-';
      for (long long i = 0; i < 4 - temp; i++) {
        a += 'O';
      }
      x /= 10;
      ans.push_back(a);
    }
  }
  for (long long i = 0; i < ans.size(); i++) {
    cout << ans[i] << '\n';
  };
}
