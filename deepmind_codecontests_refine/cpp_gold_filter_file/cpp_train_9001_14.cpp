#include <bits/stdc++.h>
using namespace std;
int a[1000010];
int far[1000010];
int main() {
  int n, q;
  cin.sync_with_stdio(false);
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long b;
  while (q--) {
    cin >> b;
    long long sum = 0;
    int right = 0;
    int left = 0;
    int smallest = -1;
    int smallestindex = 0;
    while (left < n) {
      while (right < left + n && sum + a[right % n] <= b) {
        sum += a[right % n];
        right++;
      }
      far[left] = right - left;
      if (smallest == -1 || smallest > far[left]) {
        smallest = far[left];
        smallestindex = left;
      }
      sum -= a[left];
      left++;
    }
    long long ans = -1;
    for (int i = smallestindex; i <= smallestindex + smallest; i++) {
      long long temp = 0;
      int k = i % n;
      int j = k;
      while (j < k + n) {
        temp++;
        j = j + far[j % n];
      }
      if (ans == -1 || ans > temp) {
        ans = temp;
      }
    }
    cout << ans << endl;
  }
}
