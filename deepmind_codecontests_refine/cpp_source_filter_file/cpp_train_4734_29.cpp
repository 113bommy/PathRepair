#include <bits/stdc++.h>
using namespace std;
int main() {
  string question;
  getline(cin, question);
  string vowels = "aeiouyAEIOUY",
         constants = "bcdfghjklmnpqrstvwxzBCDFGHJKLMNPQRSTVWXZ";
  for (int i = question.length() - 1; i > 0; i--) {
    for (int v = 0; v < vowels.length(); v++) {
      if (question[i] == vowels[v]) {
        cout << "YES" << endl;
        return 0;
      }
    }
    for (int c = 0; c < constants.length(); c++) {
      if (question[i] == constants[c]) {
        cout << "NO" << endl;
        return 0;
      }
    }
  }
}
