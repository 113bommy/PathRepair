#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
int arr[N];
int main() {
  int n, counter = 0, x;
  cin >> n;
  int freq[105] = {};
  for (int i = 0; i < n; i++) {
    cin >> x;
    freq[x]++;
  }
  sort(freq, freq + 100, greater<int>());
  if (freq[0] == 0)
    cout << 1 << endl;
  else
    cout << freq[0] << endl;
  return 0;
}
