#include <bits/stdc++.h>
using namespace std;
string friends[] = {"Danil", "Olya", "Slava", "Ann", "Nikita"};
string str;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> str;
  int flag = 0;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < str.size(); j++) {
      if (str.substr(j, friends[i].size()) == friends[j]) flag == 1;
    }
  }
  (flag == 1) ? cout << "YES" : cout << "NO";
  return 0;
}
