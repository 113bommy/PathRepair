#include <bits/stdc++.h>
using namespace std;
vector<int> a;
bool p[364] = {};
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  ios::sync_with_stdio(false);
  string s;
  cin >> s;
  bool q = false;
  char a = s[0];
  q = !((a == 'A' || a == 'E' || a == 'F' || a == 'G' || a == 'I' || a == 'K' ||
         a == 'L' || a == 'M' || a == 'N' || a == 'T' || a == 'V' || a == 'W' ||
         a == 'X' || a == 'Y' || a == 'Z'));
  for (long long i = 0; i < s.length(); i++) {
    char a = s[i];
    if (!(a == 'A' || a == 'E' || a == 'F' || a == 'G' || a == 'I' ||
          a == 'K' || a == 'L' || a == 'M' || a == 'N' || a == 'T' ||
          a == 'V' || a == 'W' || a == 'X' || a == 'Y' || a == 'Z') &&
        !q) {
      cout << "NO";
      return 0;
    } else if ((a == 'A' || a == 'E' || a == 'F' || a == 'G' || a == 'I' ||
                a == 'K' || a == 'L' || a == 'M' || a == 'N' || a == 'T' ||
                a == 'V' || a == 'W' || a == 'X' || a == 'Y' || a == 'Z') &&
               q) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
  return 0;
}
