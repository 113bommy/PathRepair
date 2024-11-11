#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int sm = 0;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    int i = 0, j = n - 1, flag = 0;
    int a = 0, b = 0, mv = 0, pa = 0, push_back = 0;
    while (i <= j) {
      int curra = 0, currb = 0;
      while (curra <= push_back) {
        if (i == j + 1) {
          flag = 1;
          break;
        }
        curra += arr[i];
        i++;
      }
      if (curra > 0) {
        mv++;
        a += curra;
      }
      if (flag == 1) break;
      pa = curra;
      while (currb <= pa) {
        if (j == i - 1) {
          flag = 1;
          break;
        }
        currb += arr[j];
        j--;
      }
      push_back = currb;
      if (currb > 0) {
        mv++;
        b += currb;
      }
      if (flag == 1) break;
    }
    cout << mv << " " << a << " " << b << endl;
  }
}
