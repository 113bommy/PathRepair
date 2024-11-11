#include <bits/stdc++.h>
using namespace std;
map<int, int> mp1, mp2;
int main() {
  string str;
  cin >> str;
  int n = str.size();
  int c = 0;
  for (int i = 0; i < n;) {
    if (i + 4 < n && str.substr(i, 5) == "Danil") {
      i += 5;
      c++;
    } else if (i + 3 < n && str.substr(i, 4) == "Olya") {
      i += 4;
      c++;
    } else if (i + 4 < n && str.substr(i, 5) == "Slava") {
      i += 5;
      c++;
    } else if (i + 3 < n && str.substr(i, 3) == "Ann") {
      i += 3;
      c++;
    } else if (i + 5 < n && str.substr(i, 6) == "Nikita") {
      i += 6;
      c++;
    } else
      i++;
  }
  if (c == 1)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
