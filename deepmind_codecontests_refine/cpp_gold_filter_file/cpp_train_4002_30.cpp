#include <bits/stdc++.h>
using namespace std;
int main() {
  string inp;
  cin >> inp;
  bool up = 0, lower = 0, digit = 0;
  for (int i = 0; i < inp.size(); i++) {
    if (isupper(inp[i]))
      up++;
    else if (islower(inp[i]))
      lower++;
    else if (isdigit(inp[i]))
      digit++;
  }
  if (up && lower && digit && inp.size() >= 5)
    cout << "Correct" << endl;
  else
    cout << "Too weak" << endl;
  return 0;
}
