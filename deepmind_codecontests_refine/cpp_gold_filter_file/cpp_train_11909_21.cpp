#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> ar;
  vector<int> br;
  vector<int> cr;
  int i, j, k;
  if (n % 2 == 0) {
    cout << "-1" << endl;
    return 0;
  }
  for (i = 0; i < n; i++) {
    if (i != n - 1) {
      ar.push_back(i);
      br.push_back(i + 1);
      cr.push_back((i + i + 1) % n);
    } else {
      ar.push_back(i);
      br.push_back(0);
      cr.push_back(i);
    }
  }
  for (i = 0; i < n; i++) cout << ar[i] << " ";
  cout << endl;
  for (i = 0; i < n; i++) cout << br[i] << " ";
  cout << endl;
  for (i = 0; i < n; i++) cout << cr[i] << " ";
  cout << endl;
  return 0;
}
