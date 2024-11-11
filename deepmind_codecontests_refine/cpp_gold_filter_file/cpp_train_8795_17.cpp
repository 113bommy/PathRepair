#include <bits/stdc++.h>
using namespace std;
long long fmin(long long a, long long b) { return a < b ? a : b; }
long long fmax(long long a, long long b) { return a > b ? a : b; }
int getBit(int n, int pos) { return (n >> pos) & 1; }
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  int arr[104];
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];
  int h = -1;
  for (int i = 1; i < n; i++)
    if (arr[i] >= arr[0] && (h < 0 || arr[h] < arr[i])) h = i;
  int count = 0;
  while (h > 0) {
    count++;
    arr[0]++;
    arr[h]--;
    h = -1;
    for (int i = 1; i < n; i++)
      if (arr[i] >= arr[0] && (h < 0 || arr[h] < arr[i])) h = i;
  }
  cout << count;
}
