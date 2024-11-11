#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<long long int> arr;
  long long int temp, dist, diff1, diff2;
  for (int i = 0; i < 3; i++) {
    cin >> temp;
    arr.push_back(temp);
  }
  cin >> dist;
  sort(arr.begin(), arr.end());
  diff1 = arr[0] + dist - arr[1];
  diff2 = arr[0] + 2 * dist - arr[2];
  if (diff1 > 0 && diff1 > diff2)
    cout << diff1;
  else if (diff2 > 0)
    cout << diff2;
  else if (diff1 <= 0 && diff2 <= 0)
    cout << -1;
  return 0;
}
