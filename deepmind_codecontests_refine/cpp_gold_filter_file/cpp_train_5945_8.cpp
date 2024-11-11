#include <bits/stdc++.h>
using namespace std;
void divide(vector<long long>& d, long long n) {
  long long i;
  for (i = 1; i * i < n; i++)
    if (n % i == 0) d.push_back(i);
  if (i * i == n) d.push_back(i);
}
int main() {
  long long a, b;
  cin >> a >> b;
  vector<long long> dividersab;
  vector<long long> dividersa;
  vector<long long> dividersb;
  divide(dividersab, a + b);
  divide(dividersa, a);
  divide(dividersb, b);
  long long l = 1E18;
  int i = 0;
  for (auto m : dividersab) {
    while (i < dividersa.size() && dividersa[i] <= m) i++;
    i--;
    if (i >= 0) {
      long long k = dividersa[i];
      if ((a + b) / m >= a / k && k <= m) l = min(l, 2 * (m + (a + b) / m));
    }
  }
  i = 0;
  for (auto m : dividersab) {
    while (i < dividersb.size() && dividersb[i] <= m) i++;
    i--;
    if (i >= 0) {
      long long k = dividersb[i];
      if ((a + b) / m >= b / k && k <= m) l = min(l, 2 * (m + (a + b) / m));
    }
  }
  cout << l;
}
