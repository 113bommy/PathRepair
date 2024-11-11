#include <bits/stdc++.h>
using namespace std;
void solution() {
  long long int n;
  cin >> n;
  long long int arr[n + 6];
  long long int Max = 1234567899;
  long long int cnt = 0;
  for (long long int i = 1; i <= n; i++) {
    cin >> arr[i];
    if (Max > arr[i]) {
      Max = arr[i];
      cnt = i;
    }
  }
  long long int ct = 0;
  for (long long int i = 1; i <= n; i++) {
    if (Max == arr[i]) {
      ct++;
      if (ct == 2) {
        cout << "Still Rozdil" << endl;
        return;
      }
    }
  };
  cout << cnt << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solution();
  return 0;
}
