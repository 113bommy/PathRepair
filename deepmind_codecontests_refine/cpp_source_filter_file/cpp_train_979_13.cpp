#include <bits/stdc++.h>
using namespace std;
bool cmp(const vector<int> &a, const vector<int> &b) {
  return a.size() % 2 > b.size() % 2;
}
vector<vector<int> > s;
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  s.resize(n);
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    for (int j = 0; j < tmp; j++) {
      int tt;
      cin >> tt;
      s[i].push_back(tt);
    }
  }
  sort(s.begin(), s.end(), &cmp);
  int it = 0;
  while (it < n && s[it].size() % 2 == 1) it++;
  long long sc[2] = {};
  vector<int> odd;
  for (int i = 0; i < it; i++) odd.push_back(s[i][s[i].size() / 2]);
  sort(odd.begin(), odd.end());
  for (int i = n - 1; i >= 0; i--) sc[(n - 1 - i) % 2] += odd[i];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < s[i].size() / 2; j++)
      sc[0] += s[i][j], sc[1] += s[i][s[i].size() - 1 - j];
  cout << sc[0] << " " << sc[1] << endl;
}
