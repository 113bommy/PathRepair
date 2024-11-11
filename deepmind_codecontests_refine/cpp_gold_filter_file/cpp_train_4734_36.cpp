#include <bits/stdc++.h>
using namespace std;
bool Is_Vowel(char c) {
  if (c == 'A' || c == 'a' || c == 'E' || c == 'e' || c == 'I' || c == 'i' ||
      c == 'O' || c == 'o' || c == 'U' || c == 'u' || c == 'Y' || c == 'y')
    return true;
  return false;
}
int main() {
  string question;
  while (std::getline(std::cin, question)) {
    for (int i = question.size() - 1; i >= 0; i--) {
      if (isalpha(question[i])) {
        if (Is_Vowel(question[i]) == true)
          cout << "YES";
        else
          cout << "NO";
        break;
      }
    }
  }
  return 0;
}
