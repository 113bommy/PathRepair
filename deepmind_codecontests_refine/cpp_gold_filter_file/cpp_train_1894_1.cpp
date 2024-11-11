#include <bits/stdc++.h>
using namespace std;
bool comp(long long int st1, long long int st2) {
  if (st1 < st2) return true;
  if (st1 > st2) return false;
}
void sor(long long int arr[], int n) { sort(arr, arr + n, comp); }
int main() {
  long long int a, n, ans = 0;
  cin >> a;
  while (a--) {
    cin >> n;
    long long int x[100] = {0};
    for (int i = 0; i < n; i++) {
      cin >> x[i];
      if (x[i] == 2048) {
        ans = 1;
      }
    }
    if (ans == 1) {
      cout << "YES" << endl;
      ans = 0;
      continue;
    } else {
      sor(x, n);
      for (int i = 0; i < n; i++) {
        if (x[i] == x[i + 1] && x[i] != 0 && x[i + 1] != 0) {
          x[i + 1] = x[i] + x[i + 1];
          if (x[i + 1] == 2048) {
            ans = 1;
            break;
          }
          x[i] = 0;
          sor(x, n);
        } else {
          continue;
        }
      }
      if (ans == 1) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
    ans = 0;
  }
  return 0;
}
