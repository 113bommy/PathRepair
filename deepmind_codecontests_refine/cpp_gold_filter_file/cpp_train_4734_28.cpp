#include <bits/stdc++.h>
using namespace std;
char vowels[12] = {'a', 'e', 'i', 'o', 'u', 'y', 'A', 'E', 'I', 'O', 'U', 'Y'};
int main() {
  string letters;
  int lastLettersIdx;
  bool IsLastLetterVowels = false;
  getline(cin, letters);
  lastLettersIdx = letters.length() - 1;
  for (; lastLettersIdx >= 0; lastLettersIdx--) {
    if (letters[lastLettersIdx] != '?' && letters[lastLettersIdx] != ' ') break;
  }
  for (int checkLastletter = 0; checkLastletter < 12; checkLastletter++) {
    if (letters[lastLettersIdx] == vowels[checkLastletter])
      IsLastLetterVowels = true;
  }
  if (IsLastLetterVowels)
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}
