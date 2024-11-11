#include <bits/stdc++.h>
using namespace std;
const long long int MAX = INT_MAX;
const long long int MIN = INT_MIN;
bool sortbysec(const pair<long long int, long long int> &a,
               const pair<long long int, long long int> &b) {
  return (a.second < b.second);
}
int main() {
  long long int t, n, i;
  cin >> t;
  while (t--) {
    cin >> n;
    while (n > 0) {
      cout << n << " ";
      n--;
    }
    cout << endl;
  }
  return 0;
}
