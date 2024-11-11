#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int cnt_even[2] = {0}, cnt_odd[2] = {0};
  for (int i = 0; i < s.length(); ++i) {
    int index = s[i] - 'a';
    if (i & 1)
      cnt_odd[index]++;
    else
      cnt_even[index]++;
  }
  cout << cnt_even[0] * cnt_odd[0] + cnt_even[1] * cnt_odd[1] << " ";
  cout << ((cnt_even[0]) * (cnt_even[0] - 1) / 2) +
              ((cnt_even[1]) * (cnt_even[1] - 1) / 2) +
              ((cnt_odd[0]) * (cnt_odd[0] - 1) / 2) +
              ((cnt_odd[1]) * (cnt_odd[1] - 1) / 2) + s.length()
       << endl;
}
