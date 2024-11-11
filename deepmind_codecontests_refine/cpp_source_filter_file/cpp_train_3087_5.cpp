#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  int n;
  std::cin >> n;
  std::string s;
  std::cin >> s;
  std::string a = "";
  char prev = '-';
  set<char> vow = {'a', 'e', 'i', 'o', 'u'};
  for (size_t i = 0; i < s.size(); i++) {
    if (vow.find(prev) == vow.end()) {
      prev = s[i];
      a += s[i];
    } else {
      if (vow.find(s[i]) != vow.end()) {
        continue;
      } else {
        prev = s[i];
        a += s[i];
      }
    }
  }
  cout << a << endl;
  return 0;
}
