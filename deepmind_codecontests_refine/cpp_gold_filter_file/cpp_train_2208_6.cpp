#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int res = 0;
    bool *erased = new bool[s.size()];
    memset(erased, 0, s.size());
    vector<int> pos;
    string search[3] = {"twone", "one", "two"};
    for (int i = 0; i < 3; i++) {
      size_t idx = s.find(search[i], 0);
      while (idx != string::npos) {
        if (search[i].compare("twone") == 0) {
          pos.push_back(idx + 2);
          s[idx + 2] = '-';
        } else {
          pos.push_back(idx + 1);
          s[idx + 1] = '-';
        }
        res++;
        idx = s.find(search[i], idx + 1);
      }
    }
    cout << res << endl;
    for (auto it = pos.begin(); it != pos.end(); it++) {
      cout << (*it) + 1 << " ";
    }
    cout << endl;
  }
}
