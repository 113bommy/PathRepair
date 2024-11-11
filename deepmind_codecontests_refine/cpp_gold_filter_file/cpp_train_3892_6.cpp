#include <bits/stdc++.h>
using namespace std;
int main() {
  string str;
  cin >> str;
  int x = str.length();
  int counter[26] = {0};
  for (int i = 0; i < x; i++) {
    counter[int(str[i]) - 97]++;
  }
  int odd = 0;
  for (int i = 0; i < 26; i++) {
    if (counter[i] % 2 == 1) odd += counter[i];
  }
  if (odd == 0 || odd == 1)
    cout << "First" << endl;
  else if (odd % 2 != 0 && odd > 2)
    cout << "First" << endl;
  else
    cout << "Second" << endl;
  return 0;
}
