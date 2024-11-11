#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout << std::fixed;
  cout << std::setprecision(10);
  int n;
  cin >> n;
  vector<int> arr;
  vector<int> indIm;
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    int v;
    cin >> v;
    arr.push_back(v / 2);
    if (abs(v) % 2 == 1) {
      indIm.push_back(i);
    }
    sum += v / 2;
  }
  if (sum > 0) {
    int i = 0;
    while (sum != 0) {
      if (arr[indIm[i]] < 0) {
        sum--;
        arr[indIm[i]]--;
      }
      i++;
    }
  } else if (sum < 0) {
    int i = 0;
    while (sum != 0) {
      if (arr[indIm[i]] >= 0) {
        sum++;
        arr[indIm[i]]++;
      }
      i++;
    }
  }
  for (int i = 0; i < n; ++i) {
    cout << arr[i] << "\n";
  }
  return 0;
}
