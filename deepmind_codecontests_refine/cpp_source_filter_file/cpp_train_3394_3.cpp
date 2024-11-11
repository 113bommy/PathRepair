#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, A;
  cin >> n >> A;
  int ct[1000000 + 1] = {0};
  while (n--) {
    int temp;
    cin >> temp;
    if (temp == A) {
      ct[temp]++;
    } else if (ct[temp] >= ct[A]) {
      ct[temp]++;
    }
  }
  int maxVal = -1;
  int maxCt = 0;
  for (int i = 1; i <= 1000000; i++) {
    if (ct[i] > ct[A] && i != A) {
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
