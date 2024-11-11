#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  int a;
  cin >> a;
  for (int i = 0; i < a; ++i) {
    string s;
    cin >> s;
    if (s[s.size() - 1] == 'o' && s[s.size() - 2] == 'p') {
      cout << "FILIPINO\n";
    }
    if ((s[s.size() - 1] == 'u' && s[s.size() - 2] == 's' &&
         s[s.size() - 3] == 'e' && s[s.size() - 4] == 'd') ||
        (s[s.size() - 1] == 'u' && s[s.size() - 2] == 's' &&
         s[s.size() - 3] == 'e' && s[s.size() - 4] == 'm')) {
      cout << "JAPANESE\n";
    }
    if (s[s.size() - 1] == 'a' && s[s.size() - 2] == 'd' &&
        s[s.size() - 3] == 'i' && s[s.size() - 4] == 'n' &&
        s[s.size() - 5] == 'm') {
      cout << "KOREAN\n";
    }
  }
  return 0;
}
