#include <bits/stdc++.h>
using namespace std;
long long int a[1010101];
void solve() {
  long long int n;
  cin >> n;
  long long int sum = 0;
  long long int ans = -100001;
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  for (long long int i = 0; i < n; i++) {
    for (long long int j = i; j < n; j++) {
      long long int check = 0;
      for (long long int k = i; k < j; k++) {
        if (a[k] == 1) {
          check--;
        } else {
          check++;
        }
      }
      ans = max(ans, check);
    }
  }
  cout << ans + sum << endl;
}
int main(void) { solve(); }
