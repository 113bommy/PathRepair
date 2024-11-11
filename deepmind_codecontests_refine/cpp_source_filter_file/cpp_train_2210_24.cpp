#include <bits/stdc++.h>
using namespace std;
int main() {
  long long arr[11], narr[11];
  long long size;
  cin >> size;
  for (int i = 0; i < 11; i++) arr[i] = narr[i] = 0;
  for (int i = 0; i < size; i++) {
    long long temp;
    cin >> temp;
    if (temp == 0)
      arr[0]++;
    else if (temp > 0)
      arr[temp]++;
    else {
      narr[abs(temp)]++;
    }
  }
  long long ans = 0;
  ans += (arr[0] * (arr[0] - 1)) / 2;
  for (int i = 1; i < size; i++) {
    ans += arr[i] * narr[i];
  }
  cout << ans << endl;
}
