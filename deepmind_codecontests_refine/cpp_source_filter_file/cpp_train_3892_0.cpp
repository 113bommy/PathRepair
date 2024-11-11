#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int alphabet[26] = {0};
  for (int i = 0; s[i]; i++) {
    alphabet[(int)(s[i] - 'a')]++;
  }
  int odd = 0;
  vector<int> arr;
  for (int i = 0; i < 26; i++) {
    if (alphabet[i] % 2 == 0) {
      odd++;
      arr.push_back(alphabet[i]);
    }
  }
  if (odd <= 1)
    cout << "First";
  else if (odd == 2)
    cout << "Second";
  else {
    if (odd % 2)
      cout << "First";
    else
      cout << "Second";
  }
}
