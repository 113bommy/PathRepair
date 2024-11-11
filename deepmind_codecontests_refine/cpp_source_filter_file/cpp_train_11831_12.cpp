#include <bits/stdc++.h>
int main() {
  using namespace std;
  char input[50] = {0};
  cin >> input;
  int i;
  int n = 0;
  for (i = 0; i < 50; i++)
    if (input[i] == 'a' || input[i] == 'e' || input[i] == 'i' ||
        input[i] == 'o' || input[i] == 'u' || input[i] == '0' ||
        input[i] == '2' || input[i] == '4' || input[i] == '6' ||
        input[i] == '8')
      n = n + 1;
  cout << n;
  return 0;
}
