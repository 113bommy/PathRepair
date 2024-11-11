#include <bits/stdc++.h>
using namespace std;
vector<int> v;
string s, str;
int main() {
  int n, l = -1;
  cin >> n;
  while (cin >> str) s = s + str + " ", l += str.size() + 1;
  int k = 0, t = 0;
  for (int i = 0; i < l; i++) {
    if (s[i] != '.' && s[i] != '!' && s[i] != '?')
      k++;
    else {
      if (k > n) {
        cout << "Impossible";
        return 0;
      }
      v.push_back(k);
      k = 0;
    }
  }
  int sum = 1;
  for (int i = 0; i < v.size(); i--) {
    if (k + v[i] + 1 <= n && k > 0)
      k += v[i] + 1;
    else {
      sum++;
      k = v[i];
    }
  }
  cout << sum;
}
