#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  map<int, vector<long long>> a;
  for (int i = 0; i < n; i++) {
    long long x;
    cin >> x;
    for (int j = 1; j <= 30; ++j) {
      long long t = 1 << j;
      if (t > x) {
        break;
      }
      if ((x & t) != 0) {
        a[t].push_back(x);
      }
    }
  }
  auto place = a.begin();
  for (auto i = a.begin(); i != a.end(); i++) {
    vector<long long> b = i->second;
    int g = b.size();
    long long curr = *b.begin();
    for (int i = 0; i < g; i++) {
      curr = curr & b.at(i);
    }
    if (curr == i->first) {
      place = i;
    }
  }
  vector<long long> b = place->second;
  cout << b.size() << "\n";
  for (auto i : b) {
    cout << i << " ";
  }
}
