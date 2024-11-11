#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long n;
  cin >> n;
  long long arr[n];
  cin >> arr[0];
  long long c = 1, maxx = 1;
  for (long long i = 1; i < n; i++) {
    cin >> arr[i];
    if (arr[i] > arr[i - 1]) {
      c++;
    } else {
      maxx = max(c, maxx);
      c = 1;
    }
  }
  maxx = max(c, maxx);
  cout << maxx;
  return 0;
}
