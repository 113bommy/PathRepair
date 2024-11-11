#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<string> s;
  int n;
  cin >> n;
  cin.ignore(36767, '\n');
  for (int i = 0; i < n; ++i) {
    string temp;
    getline(cin, temp);
    if (temp.find("child") != -1) {
      int x = temp.find("child");
      temp.erase(x, 5);
      temp += "woman";
    }
    s.push_back(temp);
  }
  string priority[4] = {"rat", "woman", "man", "captain"};
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < s.size(); ++j) {
      if (s[j].find(priority[i]) != -1) {
        int x = s[j].find(priority[i]);
        s[j].erase(x - 1);
        cout << s[j] << endl;
      }
    }
  }
  return 0;
}
