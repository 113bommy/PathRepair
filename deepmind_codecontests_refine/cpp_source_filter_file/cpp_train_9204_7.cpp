#include <bits/stdc++.h>
using namespace std;
vector<int> v[200];
int n;
int num[2];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    int p;
    cin >> p;
    for (int j = 0; j < p; j++) {
      int x;
      cin >> x;
      v[i].push_back(x);
    }
  }
  vector<int> t;
  for (int i = 0; i < n; i++)
    if (v[i].size() % 2 == 1) t.push_back(v[i][v[i].size() / 2]);
  sort(t.begin(), t.end());
  reverse(t.begin(), t.end());
  for (int i = 0; i < n; i++) num[i % 2] += t[i];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < v[i].size() / 2; j++) num[0] += v[i][j];
    for (int j = (v[i].size() + 1) / 2; j < v[i].size(); j++) num[1] += v[i][j];
  }
  cout << num[0] << " " << num[1] << endl;
}
