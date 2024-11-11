#include <bits/stdc++.h>
using namespace std;
int main() {
  string question;
  getline(cin, question);
  for (int i = question.size() - 1; i > 0; i--) {
    char tmp;
    tmp = question.at(i);
    if (isalpha(question.at(i))) {
      tmp = toupper(tmp);
      if (tmp == 'A' || tmp == 'E' || tmp == 'I' || tmp == 'O' || tmp == 'U' ||
          tmp == 'Y') {
        cout << "YES" << endl;
        break;
      } else {
        cout << "NO" << endl;
        break;
      }
    }
  }
  return 0;
}
