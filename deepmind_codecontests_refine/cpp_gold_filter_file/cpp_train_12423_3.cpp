#include <bits/stdc++.h>
using namespace std;
int main() {
  string a;
  cin >> a;
  string s;
  cin >> s;
  int k, j = 0;
  vector<int> v;
  vector<unsigned int> v1;
  for (int i = 0; i < a.size(); i++) {
    k = (int)a[i] - 48;
    v.push_back(k);
  }
  for (int i = 0; i < s.size(); i++) {
    k = (int)s[i] - 48;
    v1.push_back(k);
  }
  sort(v1.begin(), v1.end(), greater<int>());
  for (int i = 0; i < v.size(); i++) {
    if (v[i] < v1[j]) {
      v[i] = v1[j];
      if (j < v1.size()) {
        j++;
      }
    }
    if (j == v1.size()) {
      break;
    }
  }
  for (int i = 0; i < v.size(); i++) {
    cout << v[i];
  }
  cout << endl;
  return 0;
}
