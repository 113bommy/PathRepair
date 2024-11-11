#include <bits/stdc++.h>
using namespace std;
const int MN = 1e5 + 10;
const int MOD = 1e9 + 7;
using pi = pair<long long, long long>;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  cin >> n;
  long long sum = 0;
  long long sum2 = 0;
  for (int i = 0; i < n; i++) {
    long long num;
    cin >> num;
    sum += num;
  }
  for (int i = 0; i < n; i++) {
    long long num;
    cin >> num;
    sum2 += num;
  }
  if (sum == sum2) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
