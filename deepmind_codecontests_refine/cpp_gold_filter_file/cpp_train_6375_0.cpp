#include <bits/stdc++.h>
const long long md = 1e9 + 7;
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  long long triple, triple1, triple2, triple3, triple4, straight, straight1,
      straight2, straight3, straight4, diff1, diff2;
  long long triple_old1, triple_old2, triple_old3, triple_old4, straight_old1,
      straight_old2, straight_old3, straight_old4, straight_temp,
      straight_temp1;
  cin >> triple >> straight;
  int rm = n % 4;
  int times = n / 4 - 1;
  long long ans[n + 4];
  long long temp[n + 4];
  for (int i = 0; i < n + 4; i++) ans[i] = 0;
  for (int i = 0; i < n + 4; i++) temp[i] = 0;
  cout << "+ " << 3 << endl;
  cin >> triple_old1 >> straight_old1;
  cout << "+ " << 1 << endl;
  cin >> triple_old2 >> straight_old2;
  cout << "+ " << 2 << endl;
  cin >> triple_old3 >> straight_old3;
  cout << "+ " << 1 << endl;
  cin >> triple_old4 >> straight_old4;
  straight_temp = straight_old4;
  straight_old4 = straight_old4 - straight_old3;
  straight_old3 = straight_old3 - straight_old2;
  straight_old2 = straight_old2 - straight_old1;
  straight_old1 = straight_old1 - straight;
  ans[3] = straight_old4 - straight_old2 - 1;
  diff1 = triple_old2 - triple_old1;
  diff2 = triple_old4 - triple_old3;
  if ((diff1 == 0) && (diff2 == 0))
    ans[1] = 0;
  else if ((diff1 == 0) && (diff2 == 1))
    ans[1] = 1;
  else
    ans[1] = (sqrt(8 * diff1 + 1) + 1) / 2;
  ans[2] = straight_old2 / (ans[3] + 1);
  ans[4] = (straight_old3 - (ans[1] + 1) * (ans[3] + 1)) / (ans[3] + 1);
  temp[1] = ans[1] + 2;
  temp[2] = ans[2] + 1;
  temp[3] = ans[3] + 1;
  temp[4] = ans[4];
  int index = 5;
  while (times-- > 0) {
    cout << "+ " << index + 2 << endl;
    cin >> triple1 >> straight1;
    cout << "+ " << index << endl;
    cin >> triple2 >> straight2;
    cout << "+ " << index + 1 << endl;
    cin >> triple3 >> straight3;
    cout << "+ " << index << endl;
    cin >> triple4 >> straight4;
    straight_temp1 = straight4;
    straight4 = straight4 - straight3;
    straight3 = straight3 - straight2;
    straight2 = straight2 - straight1;
    straight1 = straight1 - straight_temp;
    straight_temp = straight_temp1;
    ans[index + 2] = straight4 - straight2 - 1 - temp[index - 1];
    diff1 = triple2 - triple1;
    diff2 = triple4 - triple3;
    if ((diff1 == 0) && (diff2 == 0))
      ans[index] = 0;
    else if ((diff1 == 0) && (diff2 == 1))
      ans[index] = 1;
    else
      ans[index] = (sqrt(8 * diff1 + 1) + 1) / 2;
    ans[index + 1] = (straight2 - temp[index - 1] * temp[index - 2]) /
                     (temp[index - 1] + ans[index + 2] + 1);
    ans[index + 3] = (straight3 - temp[index - 1] * (ans[index] + 1) -
                      (ans[index] + 1) * (ans[index + 2] + 1)) /
                     (ans[index + 2] + 1);
    triple_old1 = triple1;
    triple_old2 = triple2;
    triple_old3 = triple3;
    triple_old4 = triple4;
    straight_old1 = straight1;
    straight_old2 = straight2;
    straight_old3 = straight3;
    straight_old4 = straight4;
    temp[index] = ans[index] + 2;
    temp[index + 1] = ans[index + 1] + 1;
    temp[index + 2] = ans[index + 2] + 1;
    temp[index + 3] = ans[index + 3];
    index += 4;
  }
  if (rm == 3) {
    cout << "+ " << index - 1 << endl;
    cin >> triple1 >> straight1;
    cout << "+ " << index << endl;
    cin >> triple2 >> straight2;
    cout << "+ " << index + 1 << endl;
    cin >> triple3 >> straight3;
    straight3 = straight3 - straight2;
    straight2 = straight2 - straight1;
    straight1 = straight1 - straight_temp;
    long long c1 = straight1 - temp[index - 3] * temp[index - 2];
    long long c2 = straight2 - temp[index - 2] * (temp[index - 1] + 1);
    long long c3 = straight3 - (temp[index - 1] + 1);
    long long a1 = c3 + temp[index - 1] + 1;
    long long a2 =
        temp[index - 2] * (temp[index - 1] + 1) - c2 + c3 * temp[index - 2];
    long long a3 = c1 * c2 + c2 * temp[index - 2];
    if (c2 == 0)
      ans[index + 1] = 0;
    else
      ans[index + 1] = (sqrt(a2 * a2 + 4 * a1 * a3) - a2) / (2 * a1);
    if (c3 == 0) {
      ans[index] = 0;
      ans[index + 2] = 0;
    } else {
      ans[index] = (c1) / (temp[index - 2] + ans[index + 1]);
      ans[index + 2] =
          (c3 - (temp[index - 1] + 1) * ans[index]) / (ans[index] + 1);
    }
  } else if (rm == 2) {
    cout << "+ " << index - 1 << endl;
    cin >> triple >> straight;
    cout << "+ " << index << endl;
    cin >> triple1 >> straight1;
    straight1 = straight1 - straight;
    straight = straight - straight_temp;
    ans[index + 1] = (straight1 - temp[index - 2] * (temp[index - 1] + 1)) /
                     (temp[index - 1] + 1);
    ans[index] = (straight - temp[index - 3] * temp[index - 2]) /
                 (temp[index - 2] + ans[index + 1]);
  } else if (rm == 1) {
    cout << "+ " << index - 1 << endl;
    cin >> triple >> straight;
    straight = straight - straight_temp;
    ans[index] =
        (straight - temp[index - 3] * temp[index - 2]) / temp[index - 2];
  } else
    ;
  cout << "!";
  for (int i = 1; i < n + 1; i++) cout << " " << ans[i];
  cout << endl;
  return 0;
}
