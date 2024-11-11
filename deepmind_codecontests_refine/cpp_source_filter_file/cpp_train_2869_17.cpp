#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string ary[n], temp;
  int temp_len;
  for (int i = 0; i < n; i++) {
    cin >> ary[i];
  }
  for (int i = 0; i < n; i++) {
    temp = ary[i];
    temp_len = temp.length();
    if (temp_len > 10) {
      cout << temp[0] << temp_len - 2 << temp[temp_len - 1] << endl;
    } else {
      cout << "temp" << endl;
    }
  }
}
