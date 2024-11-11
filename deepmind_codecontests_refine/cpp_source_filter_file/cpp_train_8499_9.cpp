#include <bits/stdc++.h>
using namespace std;
string t;
char c;
int main() {
  cin >> t;
  for (int i = 0; i < t.size(); i++) {
    while (c != t[i]) {
      printf("..\nX.\n");
      c--;
    }
    printf("X.");
  }
  return 0;
}
