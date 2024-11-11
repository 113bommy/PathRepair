#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int main() {
  long long int ip, count = 0;
  string str;
  cin >> ip >> str;
  for (auto i = 1; i < ip; i += 2) {
    if (str[i - 1] != str[i]) count++;
  }
  cout << count << '\n';
  for (auto i = 0; i < ip; i += 2) {
    if (str[i] == 'a')
      cout << "a"
           << "b";
    else
      cout << "b"
           << "a";
  }
  cout << '\n';
  return 0;
}
