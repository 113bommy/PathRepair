#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  long long cost = 0;
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    mp[a] = 1;
  }
  int k = 0;
  vector<int> vec;
  for (int i = 1; i < 1000000000; i++) {
    if (mp.count(i) == 0) {
      cost += i;
      if (cost > m) break;
      vec.push_back(i);
      k++;
    }
  }
  cout << k << endl;
  for (int i = 0; i < k; i++) cout << vec[i] << " ";
}
