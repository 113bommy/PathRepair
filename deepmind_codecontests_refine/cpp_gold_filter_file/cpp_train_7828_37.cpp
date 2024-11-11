#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, arr[100], counter = 0, pairs = 0;
  cin >> n;
  int freq[101] = {};
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    freq[arr[i]]++;
    ;
  }
  for (int i = 0; i <= 100; i++) {
    while (freq[i] >= 4) {
      freq[i] -= 4;
      counter++;
    }
    while (freq[i] >= 2) {
      pairs++;
      freq[i] -= 2;
    }
    if (pairs == 2) {
      counter++;
      pairs = 0;
    }
  }
  cout << counter;
  return 0;
}
