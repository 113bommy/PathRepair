#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, a, c = 0, d, g = 0;
  cin >> n;
  vector<int> v;
  d = n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    v.push_back(a);
  }
  for (int i = 0; i < v.size(); i++) {
    for (int j = i + 1; j < v.size(); j++) {
      if (v[i] == v[j]) {
        c++;
        v.erase(v.begin() + j);
        j--;
      }
    }
    if (c > g) g = c;
    c = 0;
  }
  cout << g + 1 << " " << v.size() << endl;
  return 0;
}
