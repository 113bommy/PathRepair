#include <bits/stdc++.h>
using namespace std;
int main() {
  char Football[1000];
  char C;
  bool accept = false;
  cin >> Football;
  int len = strlen(Football);
  for (int i = 0; i < len; i++) {
    C = Football[i];
    if (Football[i] = C && Football[i + 1] == C && Football[i + 2] == C &&
                      Football[i + 3] == C && Football[i + 4] == C &&
                      Football[i + 5] == C && Football[i + 6] == C) {
      accept = true;
      break;
    }
  }
  if (accept == true)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
