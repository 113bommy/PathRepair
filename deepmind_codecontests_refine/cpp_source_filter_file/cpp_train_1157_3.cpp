#include <bits/stdc++.h>
using namespace std;
int N;
int maxn = 100000;
int arr[1001];
int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> arr[i];
  }
  for (int k = 0; k < N; ++k) {
    int tmp = 0;
    for (int l = 0; l < N; ++l) {
      tmp += arr[l] * 2 * (abs(l - k) + l + k);
    }
    maxn = min(tmp, maxn);
  }
  cout << maxn;
}
