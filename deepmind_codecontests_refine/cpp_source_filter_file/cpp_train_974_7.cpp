#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long int n;
  cin >> n;
  long long int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long int count = 0;
  for (int i = 1; i < n; i++) {
    if (a[i - 1] > a[i]) {
      count++;
    }
  }
  cout << count << endl;
}
