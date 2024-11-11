#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, a;
  cin >> n;
  vector<long long int> vec(n), copie;
  for (long long int i(0); i < n; i++) {
    cin >> a;
    vec.push_back(a);
  }
  reverse(begin(vec), end(vec));
  copie.push_back(0);
  int maxi = vec[0];
  for (long long int i(1); i < n; i++) {
    if (vec[i] < maxi)
      copie.push_back(maxi - vec[i] + 1);
    else {
      copie.push_back(0);
      maxi = vec[i];
    }
  }
  for (long long int i(n - 1); i >= 0; i--) {
    cout << copie[i] << " ";
  }
  cout << endl;
  return 0;
}
