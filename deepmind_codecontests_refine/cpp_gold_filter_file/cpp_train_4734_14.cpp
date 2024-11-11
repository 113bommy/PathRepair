#include <bits/stdc++.h>
using namespace std;
const double PI = std::atan(1.0) * 4;
int main(int argc, char* argv[]) {
  string s;
  getline(cin, s);
  string vowels = "aeiouy";
  int question = s.find('?');
  int p = question - 1;
  while (p >= 0) {
    if (isalpha(s[p])) {
      char c = tolower(s[p]);
      for (int i = 0; i < vowels.size(); ++i) {
        if (c == vowels[i]) {
          cout << "YES" << endl;
          return EXIT_SUCCESS;
        }
      }
      cout << "NO" << endl;
      return EXIT_SUCCESS;
    }
    --p;
  }
  cout << "NO" << endl;
  return EXIT_SUCCESS;
}
