#include <bits/stdc++.h>
using namespace std;
int main() {
  string brackets;
  cin >> brackets;
  int open = 0, complete = 0;
  for (int i = 0; i < brackets.size(); i++) {
    if (brackets[i] == '(')
      open++;
    else if (brackets[i] == ')' && open > 0) {
      open--;
      complete++;
    }
  }
  int sequence = complete * 2;
  cout << sequence;
}
