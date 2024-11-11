#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int i, n, sum = 0, count1 = 0, count2 = 0, count3 = 0, count4 = 0, l, min1;
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> l;
    if (l == 1)
      count1++;
    else if (l == 2)
      count2++;
    else if (l == 3)
      count3++;
    else if (l == 4)
      count4++;
  }
  sum = sum + min(count1, count2);
  count3 += sum;
  count1 -= sum;
  count2 -= sum;
  if (count1) {
    int temp = (count1) / 3;
    sum += 2 * temp;
    count3 += temp;
    count1 = count1 % 3;
    if (count1 == 1) {
      if (count3 > 0) {
        cout << sum + 1;
        return 0;
      } else if (count4 > 1) {
        cout << sum + 2;
        return 0;
      } else {
        cout << -1;
        return 0;
      }
    } else if (count1 == 2) {
      if (count3 > 1) {
        cout << sum + 2;
        return 0;
      } else if (count4 >= 1) {
        cout << sum + 2;
        return 0;
      } else {
        cout << -1;
        return 0;
      }
    } else {
      cout << sum;
    }
  } else {
    int temp = (count2) / 3;
    sum += 2 * temp;
    count3 += 2 * temp;
    count2 = count2 % 3;
    if (count2 > 0) {
      if (count2 == 1) {
        if (count4 >= 1) {
          cout << sum + 1;
          return 0;
        }
        if (count3 > 1) {
          cout << sum + 2;
          return 0;
        } else {
          cout << -1;
          return 0;
        }
      } else if (count2 == 2) {
        cout << sum + 2;
      }
    } else
      cout << sum;
  }
}
