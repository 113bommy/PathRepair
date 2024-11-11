#include <bits/stdc++.h>
using namespace std;
int N, X;
int arr[100001];
int one[100001], zero[100001], two[100001];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> X;
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
    zero[arr[i]]++;
  }
  for (int i = 1; i <= 100000; i++) {
    if (zero[i] >= 2) {
      cout << 0 << endl;
      return 0;
    }
  }
  for (int i = 0; i < N; i++) {
    if ((arr[i] & X) != arr[i]) one[arr[i] & X]++;
  }
  for (int i = 0; i < N; i++) {
    if (one[arr[i]] > 0) {
      cout << 1 << endl;
      return 0;
    }
  }
  for (int i = 0; i <= 100000; i++) {
    if (one[i] >= 2) {
      cout << 2 << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
