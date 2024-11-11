#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long* arr = new long long[n];
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    sum += arr[i];
  }
  if (sum & 1) {
    cout << "NO" << endl;
    return 0;
  }
  map<long long, int> first_half, second_half;
  first_half[arr[0]] = 1;
  for (int i = 0; i < n; i++) {
    second_half[arr[i]]++;
  }
  long long s_alt = 0;
  for (int i = 0; i < n; i++) {
    s_alt += arr[0];
    if (s_alt == sum / 2) {
      cout << "YES" << endl;
      return 0;
    }
    if (s_alt < sum / 2) {
      long long diff = sum / 2 - s_alt;
      if (second_half[diff] > 0) {
        cout << "YES" << endl;
        return 0;
      }
    } else {
      long long diff = s_alt - sum / 2;
      if (first_half[diff] > 0) {
        cout << "YES" << endl;
        return 0;
      }
    }
    first_half[arr[i + 1]]++;
    second_half[arr[i + 1]]--;
  }
  cout << "NO" << endl;
  return 0;
}
