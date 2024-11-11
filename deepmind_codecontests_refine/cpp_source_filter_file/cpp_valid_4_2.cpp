#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  vector<int> v;
  while (t > 0) {
    long long int n;
    cin >> n;
    while (n % 2 == 1) {
      n--;
    }
    cout << 2 << " " << n / 2 << endl;
    t--;
  }
}
