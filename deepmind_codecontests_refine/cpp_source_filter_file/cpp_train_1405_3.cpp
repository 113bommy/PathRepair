#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int num;
  cin >> num;
  int a[num];
  int q = 0;
  for (long long i = 0; i < (long long)num; i++) {
    cin >> a[i];
  }
  int result = num - a[0];
  for (long long i = 0; i < (long long)num; i++) {
    if (i % 2 == 0)
      a[i] = (a[i] + result) % num;
    else {
      if (result <= a[i])
        a[i] = (a[i] - result) % (num - 1);
      else {
        a[i] = (num - 1) - (result - 1);
      }
    }
    if (a[i] == i) q++;
  }
  if (q == num)
    cout << "Yes";
  else
    cout << "No";
}
