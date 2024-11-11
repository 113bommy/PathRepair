#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t-- > 0) {
    string str;
    cin >> str;
    vector<long> inds;
    long i = 0;
    while (i < str.size()) {
      if (i < str.size() - 2 && str[i] == 'o' && str[i + 1] == 'n' &&
          str[i + 2] == 'e') {
        inds.push_back(i + 1);
        i += 3;
      } else if (i < str.size() - 2 && str[i] == 't' && str[i + 1] == 'w' &&
                 str[i + 2] == 'o') {
        if (i < str.size() - 4 && str[i + 3] == 'n' && str[i + 4] == 'e') {
          inds.push_back(i + 2);
          i += 5;
          continue;
        }
        inds.push_back(i + 1);
        i += 3;
      } else
        i++;
    }
    cout << inds.size() << "\n";
    for (int i = 0; i < inds.size(); i++) {
      cout << (inds[i] + 1) << " ";
    }
    cout << "\n";
  }
  return 0;
}
