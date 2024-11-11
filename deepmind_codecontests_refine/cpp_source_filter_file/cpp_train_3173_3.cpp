#include <bits/stdc++.h>
using namespace std;
int main() {
  int freq1;
  float freq2;
  cin >> freq1 >> freq2;
  int arr[freq1];
  float rep = 0, rep2 = 0;
  int max1 = INT_MIN;
  int min1 = INT_MAX;
  for (int i = 0; i < freq1; i++) cin >> arr[i];
  for (int i = 0; i < freq1 - 1; i++) {
    max1 = max(max1, arr[i]);
    min1 = min(min1, arr[i]);
  }
  rep = ((max1 - min1) / freq2);
  if (rep > 1) {
    cout << "NO";
    return 0;
  }
  cout << "YES"
       << "\n";
  for (int i = 0; i < freq1; i++) {
    int k = 1;
    for (int j = 0; j < arr[i]; j++) {
      cout << k << " ";
      if (k == freq2) {
        k = 0;
      }
      k = k + 1;
    }
    cout << "\n";
  }
}
