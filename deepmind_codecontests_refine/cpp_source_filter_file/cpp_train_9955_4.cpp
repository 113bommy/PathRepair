#include <bits/stdc++.h>
using namespace std;
string names[10] = {"Danil", "Olya", "Slava", "Ann", "Nikita"};
int cont(string& str) {
  int ans = 0;
  for (int i = 0; i < str.size(); i++)
    for (int j = 0; j < 5; j++)
      if (str.substr(i, i + names[j].size()) == names[j]) ans++;
  return ans;
}
int main() {
  string str;
  cin >> str;
  if (cont(str) == 1)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
