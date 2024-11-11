#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000 * 1000 + 10;
int t[30];
bool mark[MAXN];
int main() {
  string s, u, w;
  cin >> s;
  for (int i = 0; i < 30; i++) t[i] = -1;
  for (int i = 0; i < (int)s.size(); i++) t[s[i] - 'a'] = i;
  vector<char> vec;
  vec.push_back(s[(int)s.size() - 1]);
  for (int i = (int)s.size() - 2; i >= 0; i--)
    if (s[i] < vec[(int)vec.size() - 1]) vec.push_back(s[i]);
  reverse(vec.begin(), vec.end());
  int ind = 0;
  for (int i = 0; i < (int)s.size(); i++) {
    while (t[vec[ind] - 'a'] < i) ind++;
    while ((int)w.size() && vec[ind] >= w[(int)w.size() - 1]) {
      u += w[(int)w.size() - 1];
      w = w.substr(0, (int)w.size() - 1);
    }
    w += s[i];
  }
  for (int i = (int)w.size() - 1; i >= 0; i--) u += w[i];
  cout << u << endl;
  return 0;
}
