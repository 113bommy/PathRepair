#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, a;
  cin >> n;
  vector<long long int> vect;
  for (int i = 0; i < n; i++) {
    cin >> a;
    vect.push_back(a);
  }
  if (n <= 2) {
    cout << "0"
         << "\n";
    int i = 0;
    while (i < n) {
      cout << vect[i] << " ";
      i++;
    }
    return 0;
  }
  long long int p = vect.size();
  cout << p / 2 << "\n";
  sort(vect.begin(), vect.end());
  int j = 0;
  for (long long int i = p / 2; i < n; i++) {
    cout << vect[i] << " ";
    if (j < p / 2) cout << vect[j] << " ";
    j++;
  }
  return 0;
}
