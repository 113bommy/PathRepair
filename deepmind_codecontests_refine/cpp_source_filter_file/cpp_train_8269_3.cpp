#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  pair<int, int> arr[100001];
  int a, b;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    arr[i] = make_pair(a, b);
  }
  sort(arr, arr + n - 1);
  int p = true;
  for (int i = 0; i < n - 1; i++) {
    if (arr[i + 1].second > arr[i].second)
      continue;
    else {
      p = false;
      break;
    }
  }
  if (p == false)
    cout << "Happy Alex" << endl;
  else
    cout << "Poor Alex" << endl;
  return 0;
}
