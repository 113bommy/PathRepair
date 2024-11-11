#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n;
  cin >> n;
  vector<long long int> arr(n);
  for (int i = 0; i < n; i++) cin >> arr[i];
  if (n == 1) {
    cout << 0;
    return 0;
  }
  vector<pair<long long int, long long int>> prefix(n);
  long long int sumO = 0, sumE = 0, ans = 0;
  for (int i = 0; i < n; i++) {
    if ((i + 1) % 2 == 1)
      sumO += arr[i];
    else if ((i + 1) % 2 == 0)
      sumE += arr[i];
    prefix[i] = make_pair(sumO, sumE);
  }
  for (int i = 0; i < n; i++) {
    long long int nobita = i + 1, sumEven = 0, sumOdd = 0;
    if (nobita == 1) {
      sumEven += prefix[n - 1].first - prefix[0].first;
      sumOdd += prefix[n - 1].second - prefix[0].second;
    } else if (nobita > 1) {
      sumEven += prefix[nobita - 2].second;
      sumOdd += prefix[nobita - 2].first;
      if (nobita < n) {
        sumEven += prefix[n - 1].first - prefix[nobita - 1].first;
        sumOdd += prefix[n - 1].second - prefix[nobita - 1].second;
      }
    }
    if (sumOdd == sumEven) ans++;
  }
  cout << ans;
  return 0;
}
