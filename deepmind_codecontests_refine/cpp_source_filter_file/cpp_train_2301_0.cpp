#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int arr[n];
  int freq[101] = {0};
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    freq[arr[i]]++;
  }
  sort(freq, freq + 101, greater<int>());
  int max = freq[0];
  int num = 0;
  for (int i = 0; i < 101; i++) {
    if (freq[i] > 0) {
      num++;
    }
  }
  int b;
  int a = (float)k;
  int c = (float)max;
  if (k > max) {
    b = 1;
  } else if (a % c == 0) {
    b = max / k;
  } else if (k < max && a % c != 0) {
    b = (max / k) + 1;
  }
  cout << (b * k * num) - n << endl;
}
