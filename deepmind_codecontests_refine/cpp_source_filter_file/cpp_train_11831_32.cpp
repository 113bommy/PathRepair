#include <bits/stdc++.h>
using namespace std;
int main() {
  char str[100];
  cin >> str;
  int total = 0;
  for (int i = 0; i < (int)strlen(str); i++) {
    if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' ||
        str[i] == 'u' || str[i] == '0' || str[i] == '2' || str[i] == '4' ||
        str[i] == '6' || str[i] == '8')
      total++;
  }
  cout << total;
}
