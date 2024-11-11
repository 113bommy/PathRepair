#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t = 1;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << n << endl;
    for (int i = n; i >= 1; i--) {
      cout << i << " ";
    }
    cout << endl;
  }
}
