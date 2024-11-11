#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int n;
  cin >> n;
  string str;
  getline(cin, str);
  for (int i = 0; i < n; i++) {
    getline(cin, str);
    int m = str.length();
    if (m < 5) {
      cout << "OMG>.< I don't know!" << endl;
      continue;
    }
    string begin = str.substr(0, 5);
    string end = str.substr(m - 5, 5);
    if (begin == "miao." && end != "lala.")
      cout << "Rainbow's" << endl;
    else if (begin != "miao." && end == "lala.")
      cout << "Freda's" << endl;
    else
      cout << "OMG>.< I don't know!" << endl;
  }
  return 0;
}
