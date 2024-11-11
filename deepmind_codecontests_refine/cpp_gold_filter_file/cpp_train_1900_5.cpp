#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    long long int arr[100005];
    arr[0] = arr[n + 1] = 0;
    bool f = false, F = false;
    for (int i = 1; i <= n; i++) {
      cin >> arr[i];
      if (arr[i] == k) f = true;
    }
    for (int i = 1; i <= n; i++)
      if ((arr[i] >= k && arr[i + 1] >= k) ||
          (arr[i - 1] >= k && arr[i + 1] >= k))
        F = 1;
    cout << (((f & F) || (f && n == 1)) ? "yes\n" : "no\n");
  }
  return 0;
}
