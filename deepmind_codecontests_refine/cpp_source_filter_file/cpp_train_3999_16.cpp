#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> v;
  int magnet;
  int size, cnt = 0;
  cin >> size;
  for (int i = 0; i < size; ++i) {
    cin >> magnet;
    v.push_back(magnet);
  }
  for (int i = 0; i < v.size(); ++i) {
    if (v[i] == v[i + 1] && i + 1 != v.size()) {
      cnt++;
    }
  }
  cout << cnt;
  return 0;
}
