#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[n];
  int one = 0, two = 0, three = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr[n];
    int k = arr[n];
    if (k == 1) {
      one++;
    } else if (k == 2) {
      two++;
    } else if (k == 3) {
      three++;
    }
  }
  int maxm = max(one, max(two, three));
  cout << n - maxm << endl;
  return 0;
}
