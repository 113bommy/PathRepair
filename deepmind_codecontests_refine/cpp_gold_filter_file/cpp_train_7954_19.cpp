#include <bits/stdc++.h>
using namespace std;
int main() {
  long long l = 0, r = 0, loc, size;
  char s[1000001];
  cin >> s;
  size = strlen(s);
  for (int i = 0; i < size; i++) {
    if (s[i] == '^') {
      loc = i;
      break;
    }
  }
  for (int i = 0; i < loc; i++) {
    if (s[i] != '=') l += ((s[i] - 48) * (loc - i));
  }
  for (int i = loc + 1; i < size; i++) {
    if (s[i] != '=') r += ((s[i] - 48) * (i - loc));
  }
  if (l > r)
    cout << "left";
  else if (r > l)
    cout << "right";
  else
    cout << "balance";
}
