#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, neg = 0, pos = 0;
  cin >> n;
  long long a[n];
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    pos += (a[i] > 0);
    neg += (a[i] < 0);
  }
  long long sum = (n + 1) / 2;
  if (pos > sum)
    cout << "1" << endl;
  else if (neg > sum)
    cout << "-1" << endl;
  else
    cout << "0";
  return (0);
}
