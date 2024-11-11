#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, sum1 = 0, sum2 = 0, sum3 = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    long long e;
    cin >> e;
    sum1 += e;
  }
  for (int i = 0; i < n - 1; ++i) {
    long long e;
    cin >> e;
    sum2 += e;
  }
  for (int i = 0; i < n - 2; ++i) {
    long long e;
    cin >> e;
    sum3 += e;
  }
  cout << sum1 - sum2 << endl << sum2 - sum3 << endl;
  return 0;
}
