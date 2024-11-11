#include <bits/stdc++.h>
using namespace std;
int main() {
  int k;
  scanf("%d", &(k));
  string s, t;
  cin >> s >> t;
  vector<int> sv(k), tv(k);
  for (int i = (0); i < (k); i++) {
    sv[i] = (int(s[i] - 'a'));
    tv[i] = (int(t[i] - 'a'));
  }
  vector<int> summ;
  int rem = 0, x;
  for (int i = k - 1; i >= 0; i--) {
    x = sv[i] + tv[i] + rem;
    if (x >= 26) {
      rem = 1;
      x -= 26;
      summ.push_back(x);
    } else {
      summ.push_back(x);
      rem = 0;
    }
  }
  if (rem == 1) {
    summ.push_back(1);
  }
  reverse(summ.begin(), summ.end());
  rem = 0;
  vector<int> res;
  for (int i = (0); i < (summ.size()); i++) {
    res.push_back(((26 * rem) + summ[i]) / 2);
    if (((26 * rem) + summ[i]) % 2 == 0)
      rem = 0;
    else
      rem = 1;
  }
  vector<char> ans(res.size());
  for (int i = (res.size() - k); i < (res.size()); i++) {
    cout << char(res[i] + 97);
  }
  cout << endl;
}
