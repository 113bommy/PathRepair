#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int count1 = 0, count2 = 0;
  int res = 0;
  vector<int> ar;
  cin >> n;
  if (n == 1) {
    cout << 0 << endl;
    return 0;
  }
  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;
    if (temp == 1) {
      count1++;
    } else {
      count2++;
    }
  }
  do {
    if (count1 > 0 && count2 > 0) {
      res++;
    } else {
      break;
    }
    count1--;
    count2--;
  } while (count1 > 0 && count2 > 0);
  do {
    if (count1 >= 3) {
      res++;
      count1 -= 3;
    } else {
      count1--;
    }
  } while (count1 > 0);
  cout << res << endl;
  return 0;
}
