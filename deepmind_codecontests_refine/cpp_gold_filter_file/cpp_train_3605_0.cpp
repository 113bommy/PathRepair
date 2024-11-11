#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, ph;
  cin >> n;
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> ph;
    sum += (long long)ph;
  }
  int cola[n];
  for (int i = 0; i < n; i++) {
    cin >> cola[i];
  }
  sort(cola, cola + n);
  if ((long long)cola[n - 1] + (long long)cola[n - 2] >= sum)
    cout << "YES";
  else
    cout << "NO";
}
