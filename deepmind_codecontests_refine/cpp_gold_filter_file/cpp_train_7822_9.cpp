#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  long long int arr[n];
  for (long long int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  vector<char> v;
  long long int p = min(arr[0], arr[n - 1]);
  long long int l = 0, r = n - 1;
  if (min(arr[0], arr[n - 1]) == arr[0]) {
    v.push_back('L');
    p = arr[0];
    l++;
  } else {
    v.push_back('R');
    p = arr[n - 1];
    r--;
  }
  while (l != r) {
    if (p <= arr[l] && p <= arr[r]) {
      if (arr[l] <= arr[r] && p < arr[l]) {
        v.push_back('L');
        p = arr[l];
        l++;
      } else if (arr[r] <= arr[l] && p < arr[r]) {
        v.push_back('R');
        p = arr[r];
        r--;
      } else {
        break;
      }
    } else if (arr[r] > p && p >= arr[l]) {
      v.push_back('R');
      p = arr[r];
      r--;
    } else if (arr[l] > p && p >= arr[r]) {
      v.push_back('L');
      p = arr[l];
      l++;
    } else {
      break;
    }
  }
  if (p < arr[l] && l < n) {
    v.push_back('L');
  }
  cout << v.size() << endl;
  for (long long int i = 0; i < v.size(); i++) {
    cout << v[i];
  }
}
