#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int l = s.size();
  int zero = 0, one = 0;
  for (int i = 0; i < l; i++) {
    if (s[i] == '0')
      zero++;
    else
      one++;
  }
  if (zero != one) {
    cout << 1 << endl;
    cout << s << endl;
    ;
  } else {
    cout << 2 << endl;
    cout << s[0] << " " << s.substr(s.length() - 1) << endl;
  }
  return 0;
}
