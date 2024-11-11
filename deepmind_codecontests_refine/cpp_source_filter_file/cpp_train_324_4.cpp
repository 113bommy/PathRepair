#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
int arr[N];
int arr2[N];
char a[N];
char matrix[100][100];
int main() {
  int t;
  cin >> t;
  vector<int> v;
  vector<int> x;
  long long odd = 0;
  long long even = 0;
  long long sum = 0;
  for (int i = 0; i < t; i++) {
    cin >> arr[i];
    if (arr[i] % 2 == 1) {
      odd++;
      v.push_back(arr[i]);
    } else {
      even++;
      x.push_back(arr[i]);
    }
  }
  sort(v.begin(), v.end());
  sort(x.begin(), x.end());
  if (even == odd)
    cout << 0 << endl;
  else if (abs(even - odd) == 1)
    cout << 0 << endl;
  else if (even == 0) {
    for (int i = 0; i < v.size() - 1; i++) {
      sum += v[i];
    }
    cout << sum << endl;
  } else if (odd == 0) {
    for (int i = 0; i < x.size() - 1; i++) {
      sum += x[i];
    }
    cout << sum << endl;
  } else {
    if (odd > even) {
      for (int i = 0; i < odd - even; i++) {
        sum += v[i];
      }
    } else {
      for (int i = 0; i < even - odd; i++) {
        sum += x[i];
      }
    }
    cout << sum << endl;
  }
}
