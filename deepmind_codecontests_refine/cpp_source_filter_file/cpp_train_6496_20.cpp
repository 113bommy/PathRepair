#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned long long n, m;
  cin >> n >> m;
  vector<unsigned long long> arr;
  unsigned long long input, count = 0, i = 0;
  while (i < m) {
    cin >> input;
    arr.push_back(input);
    i++;
  }
  count = arr[0] - 1;
  for (unsigned long long i = 0; i < m - 1; i++) {
    if (arr[i] < arr[i + 1]) {
      count += arr[i + 1] - arr[i];
    } else if (arr[i] == arr[i + 1]) {
      i++;
    } else {
      count += n - arr[i] + arr[i + 1];
    }
  }
  cout << count;
  return 0;
}
