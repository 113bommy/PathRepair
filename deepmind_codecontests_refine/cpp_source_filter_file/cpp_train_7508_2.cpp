#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string str;
  cin >> str;
  bool poss = false;
  long long int n = str.length();
  char ch = str[0];
  for (int i = 0; i < str.length() / 2; i++) {
    if (str[i] != ch) poss = true;
  }
  if (!poss || n <= 3)
    cout << "Impossible" << endl;
  else {
    if (n % 2 == 0 && str.substr(0, n / 2) == str.substr(n / 2, n / 2)) {
      cout << 1 << endl;
    } else {
      bool poss1 = false;
      for (int i = 1; i <= n - 1; i++) {
        string str_shuff = str.substr(i, n - i) + str.substr(0, i),
               rev_shuff = str_shuff;
        reverse(rev_shuff.begin(), rev_shuff.end());
        if (str_shuff == rev_shuff && str_shuff != str) {
          cout << 1 << endl;
          poss1 = true;
          break;
        }
      }
      if (!poss1) {
        cout << 2 << endl;
      }
    }
  }
}
