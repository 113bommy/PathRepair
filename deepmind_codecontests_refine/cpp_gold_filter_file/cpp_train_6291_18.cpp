#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, rr = 0, temp = 0;
  cin >> n;
  vector<int> arr;
  vector<int> res;
  for (int i = 0; i < n; i++) {
    cin >> k;
    arr.push_back(k);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < arr[i]; j++) {
      cin >> k;
      rr += k * 5;
    }
    rr += arr[i] * 15;
    res.push_back(rr);
    rr = 0;
  }
  temp = res[0];
  for (int i = 1; i < n; i++)
    if (res[i] < temp) temp = res[i];
  cout << temp;
  return 0;
}
