#include <bits/stdc++.h>
using namespace std;
class MissingParentheses {
 public:
  void countCorrections() {
    int i = 0;
    int j = 0;
    char a[1004];
    char b[1004];
    gets(a);
    gets(b);
    for (int k = 0; k < strlen(a); k++)
      if (a[k] == '1') i++;
    for (int k = 0; k < strlen(b); k++)
      if (b[k] == '1') j++;
    i = ((i + 1) / 2) * 2;
    if (j <= i) {
      cout << "YES";
    } else {
      cout << "NO";
    }
  }
};
int main() {
  MissingParentheses alg;
  alg.countCorrections();
}
