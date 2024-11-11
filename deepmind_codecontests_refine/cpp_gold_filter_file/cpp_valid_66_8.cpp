#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout << fixed << setprecision(20);
  int numberOfTestcases;
  cin >> numberOfTestcases;
  for (int testcase = 0; testcase < numberOfTestcases; testcase++) {
    int k;
    cin >> k;
    int n = 1;
    while (k > 0) {
      if (n % 3 != 0 && n % 10 != 3) k--;
      n++;
    }
    cout << n - 1 << endl;
  }
  return 0;
}
