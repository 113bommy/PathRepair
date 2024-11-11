#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  vector<int> v(n + 1);
  for (int i = 2; i <= n; i++) {
    if (v[i] == 0)
      for (int j = 2; j * i < n; j++) v[i * j] = 1;
  }
  vector<int> v1;
  v1.push_back(1);
  for (int i = 2; i <= n; i++)
    if (v[i] != 0) v1.push_back(i);
  for (int i = 1; i < v1.size(); i++)
    if (binary_search(v1.begin(), v1.end(), (n - v1[i]))) {
      cout << v1[i] << " " << n - v1[i];
      break;
    }
  return 0;
}
