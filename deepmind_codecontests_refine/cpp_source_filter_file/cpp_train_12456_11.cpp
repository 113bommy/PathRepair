#include <bits/stdc++.h>
using namespace std;
const long long int sz = 1e5 + 5;
const long long int szz = 1e6 + 6;
const long long int mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);
  clock_t startTime = clock();
  long long int n;
  cin >> n;
  long long int ar[n + 5];
  for (long long int i = 1; i < n + 1; i++) {
    cin >> ar[i];
  }
  bool flag = false;
  for (long long int i = 1; i < n + 1; i++) {
    long long int curr = i;
    long long int i2 = ar[curr];
    long long int i3 = ar[i2];
    long long int curr3 = ar[i3];
    if (i == i3 and (i != i2 and i2 != i3)) {
      flag = true;
    }
  }
  if (flag) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  cerr << "\n"
       << setprecision(20)
       << double(clock() - startTime) / (double)CLOCKS_PER_SEC << " seconds."
       << "\n";
}
