#include <bits/stdc++.h>
using namespace std;
vector<int> ar, cnts;
int n, add = 0, cur = 0;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    int el;
    cin >> el;
    ar.push_back(el);
  }
  for (int i = n - 1; i >= 0; i--) {
    cur += add;
    if (cur != ar[i]) {
      int l = ar[i] - cur;
      for (int j = 0; j < l; j++) {
        add++;
        cur++;
        cnts.push_back(i + 1);
      }
    }
  }
  string s;
  for (int e = 0; e < cnts.size(); e++) {
    while (cnts[e]--) s += 'a' + (e % 26);
  }
  cout << s << endl;
  return 0;
}
