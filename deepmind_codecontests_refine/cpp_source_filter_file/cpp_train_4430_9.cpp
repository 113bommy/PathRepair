#include <bits/stdc++.h>
using namespace std;
bool prime[101];
void SieveOfEratosthenes(int n) {
  memset(prime, true, sizeof(prime));
  for (int p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (int i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    vector<int> v;
    SieveOfEratosthenes(100);
    for (int i = 2; i <= 50; i++) {
      if (prime[i] == true) {
        v.push_back(i);
      }
    }
    bool f1 = false, f2 = false;
    for (long long i = 0; i < v.size(); i++) {
      cout << v[i] << endl;
      string x;
      cin >> x;
      if (x == "yes") {
        if (f1 == true) {
          f2 = true;
          break;
        }
        f1 = true;
      }
    }
    cout << 4 << endl;
    string x;
    cin >> x;
    if (x == "yes") {
      cout << "composite" << endl;
      break;
    }
    cout << 9 << endl;
    cin >> x;
    if (x == "yes") {
      cout << "composite" << endl;
      break;
    }
    cout << 16 << endl;
    cin >> x;
    if (x == "yes") {
      cout << "composite" << endl;
      break;
    }
    cout << 25 << endl;
    cin >> x;
    if (x == "yes") {
      cout << "composite" << endl;
      break;
    } else if (f2 == true) {
      cout << "composite" << endl;
    } else {
      cout << "prime" << endl;
    }
  }
  return 0;
}
