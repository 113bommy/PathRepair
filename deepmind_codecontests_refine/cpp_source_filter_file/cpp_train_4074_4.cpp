#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int arr[7], n, one = 0, ans[7];
    cin >> n;
    for (long long int i = 0; i < 7; i++) cin >> arr[i];
    for (long long int i = 0; i < 7; i++)
      if (arr[i]) one++;
    for (long long int i = 0; i < 7; i++) {
      long long int temp[7], mixi = 0, X = n;
      for (long long int j = 0; j <= 6; j++) temp[(i + j) % 7] = arr[j];
      if (!(X % one) && X > one)
        mixi += (X / one - 1) * 7, X = one;
      else if (X > one)
        mixi += (X / one) * 7, X %= one;
      if (!X)
        ans[i] = mixi;
      else {
        for (long long int j = 0; j <= 6; j++) {
          if (arr[j]) X--;
          if (!X) {
            ans[i] = mixi + j + 1;
            break;
          }
        }
      }
    }
    int t = 100000000;
    for (long long int i = 0; i < 7; i++) t = min(t, ans[i]);
    cout << t << endl;
  }
  return 0;
}
