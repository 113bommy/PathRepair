#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int j = 0; j < t; j++) {
    string s;
    cin >> s;
    vector<int> d(s.size());
    ;
    int k = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == 'L')
        d[k]++;
      else
        k++;
    }
    cout << *max_element(d.begin(), d.end()) + 1 << endl;
  }
}
