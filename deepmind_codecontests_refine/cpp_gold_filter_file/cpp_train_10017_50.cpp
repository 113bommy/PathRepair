#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, oc = 0, ec = 0, t = 0;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    if (arr[i] % 2 == 0)
      ec++;
    else
      oc++;
    t += arr[i];
  }
  if (t % 2 == 0)
    cout << ec << endl;
  else
    cout << oc << endl;
  return 0;
}
