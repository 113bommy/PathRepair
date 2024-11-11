#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, f, m;
  cin >> n >> f >> m;
  long long int a[f];
  long long int x;
  vector<long long int> v(f, 0);
  for (long long int i = 0; i < f; i++) {
    cin >> a[i];
  }
  for (long long int j = 0; j < m; j++) {
    cin >> x;
    for (long long int i = 0; i < f; i++) {
      if (x % a[i] == 0) {
        v[i]++;
      }
    }
  }
  vector<pair<int, int>> vect;
  for (long long int i = 0; i < f; i++) {
    vect.push_back(make_pair(v[i], i + 1));
  }
  sort(vect.begin(), vect.end());
  int i = 0;
  while (vect[i].first == vect[0].first) {
    i++;
  }
  cout << i << endl;
  for (int j = 0; j < i; j++) {
    cout << vect[j].second << " ";
  }
  return 0;
}
