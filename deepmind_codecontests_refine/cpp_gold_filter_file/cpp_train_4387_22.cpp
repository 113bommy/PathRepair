#include <bits/stdc++.h>
using namespace std;
int main() {
  string str, card;
  int flag = 0;
  cin >> str;
  for (int i = 0; i < 5; i++) {
    cin >> card;
    if (str[0] == card[0] || str[1] == card[1]) flag = 1;
  }
  if (flag != 0)
    cout << "YES";
  else
    cout << "NO";
}
