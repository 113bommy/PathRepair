#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<long long> vec(n);
  for (int i = 0; i < n; i++) {
    cin >> vec[i];
  }
  long long sum = 0;
  long long mn = 0;
  for (int i = 0; i < n; i++) {
    sum += vec[i];
    mn = max(mn, vec[i]);
  }
  sum = (sum + n - 2) / (n - 1);
  mn = max(mn, sum);
  cout << mn << endl;
}
