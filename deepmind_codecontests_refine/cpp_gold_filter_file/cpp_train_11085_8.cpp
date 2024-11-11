#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  int numb = 0;
  long long int count1 = 0, count2 = 0, count3 = 0;
  for (long long int i = 0; i < n; i++) {
    cin >> numb;
    if (numb == 1) {
      count1 += 1;
    } else if (numb == 2) {
      count2 += 1;
    } else if (numb == 3) {
      count3 += 1;
    } else {
      cout << "wrong input";
    }
  }
  long long int ans = 0;
  if (count1 >= count2 && count1 >= count3) {
    ans = n - count1;
  } else if (count2 >= count3 && count2 > count1) {
    ans = n - count2;
  } else {
    ans = n - count3;
  }
  cout << ans;
  return 0;
}
