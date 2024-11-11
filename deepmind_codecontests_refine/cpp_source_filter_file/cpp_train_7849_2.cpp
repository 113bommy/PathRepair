#include <bits/stdc++.h>
using namespace std;
int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
int main() {
  int n;
  vector<int> a(1, 1);
  cin >> n;
  for (int i = 0; a.size() < n; i++) {
    for (int j = 0; j < a.size(); j++) {
      if (primes[i] * a[j] <= 2 * n * n) a.push_back(primes[i] * a[j]);
    }
  }
  sort(a.begin(), a.end(), less<int>());
  for (int i = 0; i < n; i++) cout << a[i] << " ";
  cout << endl;
}
