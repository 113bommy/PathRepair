#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string str;
  cin >> str;
  int ctr = 0;
  for (int i = 0; i < str.size(); i++) {
    if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' ||
        str[i] == 'u' || str[i] == '1' || str[i] == '3' || str[i] == '5' ||
        str[i] == '7' || str[i] == '9')
      ctr++;
  }
  cout << ctr << '\n';
  return 0;
}
