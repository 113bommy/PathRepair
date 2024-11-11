#include <bits/stdc++.h>
const int N = 4e5 + 5;
const long long int N1 = 1e15 + 5;
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long int t;
  cin >> t;
  while (t--) {
    long long int a, b;
    cin >> a >> b;
    long long int sum = (a + b) / 3;
    long long int r = min(min(a / 3, b / 3), sum);
    cout << r << endl;
  }
}
