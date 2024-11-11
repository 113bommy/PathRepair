#include <bits/stdc++.h>
using namespace std;
int main() {
  char str[100];
  cin >> str;
  int total = 0;
  for (int i = 0; i < (int)strlen(str); i++) {
    if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' ||
        str[i] == 'u' || str[i] == '1' || str[i] == '3' || str[i] == '5' ||
        str[i] == '7' || str[i] == '9')
      total++;
  }
  cout << total;
}
