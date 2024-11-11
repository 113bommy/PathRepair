#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  string line;
  vector<float> v;
  map<float, int> mp;
  for (int i = 0; i < t; ++i) {
    int a, b, c;
    char ch;
    cin >> line;
    stringstream ss(line);
    ss >> ch >> a >> ch >> b >> ch >> ch >> c;
    float tmp = (float)(a + b) / c;
    v.push_back(tmp);
    mp[tmp]++;
  }
  for (int j = 0; j < t; ++j) {
    cout << mp[v[j]] << " ";
  }
}
