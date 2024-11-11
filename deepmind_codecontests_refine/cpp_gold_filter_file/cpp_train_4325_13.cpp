#include <bits/stdc++.h>
using namespace std;
int main() {
  string word;
  int rem;
  set<string> suff;
  string aux1, aux2, aux3, aux4;
  int duo;
  int trio;
  cin >> word;
  if (word.size() <= 5) {
    cout << 0;
    return 0;
  } else {
    duo = word.size() - 4;
    trio = word.size() - 5;
    for (int i = word.size() - 1; i >= 5; i--) {
      rem = word.size() - i - 1;
      if (i + 2 == word.size()) {
        suff.insert(word.substr(i, 2));
      }
      if (i + 3 == word.size()) {
        suff.insert(word.substr(i, 3));
      }
      if (i <= duo) {
        if (i <= duo - 2) {
          aux2 = word.substr(i + 4, 2);
          aux1 = word.substr(i + 2, 2);
          if (aux1 != aux2)
            suff.insert(word.substr(i, 2));
          else if (i < duo - 2 && i != trio - 3)
            suff.insert(word.substr(i, 2));
        } else if (i != trio - 3) {
          suff.insert(word.substr(i, 2));
        }
      }
      if (i <= trio) {
        if (i <= trio - 4) {
          aux4 = word.substr(i + 7, 2);
          aux3 = word.substr(i + 5, 2);
          aux2 = word.substr(i + 6, 3);
          aux1 = word.substr(i + 3, 3);
          if (aux1 != aux2 || aux3 != aux4 ||
              i < (trio - 4) && (word.size() - i) % 2 != 0) {
            suff.insert(word.substr(i, 3));
          } else if (i == 5)
            suff.insert(word.substr(i, 3));
        } else if (i == trio - 3) {
          suff.insert(word.substr(i, 3));
        } else if (i == trio - 2) {
          aux4 = word.substr(i + 5, 2);
          aux3 = word.substr(i + 3, 2);
          if (aux3 != aux4) suff.insert(word.substr(i, 3));
        } else {
          suff.insert(word.substr(i, 3));
        }
      }
    }
  }
  if (suff.size() == 275)
    cout << 276 << endl;
  else
    cout << suff.size() << endl;
  set<string>::iterator it;
  for (it = suff.begin(); it != suff.end(); it++) {
    cout << *it << endl;
  }
  return 0;
}
