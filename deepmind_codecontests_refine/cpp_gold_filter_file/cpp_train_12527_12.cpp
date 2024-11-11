#include <bits/stdc++.h>
using namespace std;
string s;
vector<int> v;
int n;
int l, pos, g, t;
void no() {
  cout << "NO";
  exit(0);
}
int main() {
  cin >> s;
  n = s.size();
  for (int i = 0; i < n; i++)
    if (s[i] == '.') v.push_back(i);
  g = v.size();
  if (!g || v[0] > 8 || v[0] == 0 || v[g - 1] == n - 1 || v[g - 1] < n - 4)
    no();
  for (int i = 1; i < g; i++) {
    l = v[i] - v[i - 1] - 1;
    if (l > 11 || l < 2) no();
  }
  cout << "YES" << endl;
  for (int i = 1; i < g; i++) {
    t = ceil((v[i] - v[i - 1] - 1) * 3. / 11.) + v[i - 1];
    cout << s.substr(pos, t - pos + 1) << endl;
    pos = t + 1;
  }
  cout << s.substr(pos, n - pos);
}
