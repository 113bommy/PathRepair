#include <bits/stdc++.h>
int main(int argc, const char* argv[]) {
  std::string s;
  std::cin >> s;
  int result = 0;
  for (int i = 0; i < s.length(); i++) {
    for (int j = i + i; j < s.length(); j++) {
      for (int k = j + 1; k < s.length(); k++) {
        if (s[i] == 'Q' && s[j] == 'A' && s[k] == 'Q') result++;
      }
    }
  }
  std::cout << result << std::endl;
  return 0;
}
