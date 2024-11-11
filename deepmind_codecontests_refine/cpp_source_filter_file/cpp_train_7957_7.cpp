#include <bits/stdc++.h>
using namespace std;
int main() {
  string str;
  int i, k, value[1005], len;
  long long re = 0;
  cin >> str >> k;
  len = str.size();
  for (i = 0; i < 26; i++) cin >> value[i];
  for (i = 0; i < len; i++) re += value[str[i] - 'a'] * (i + 1);
  len = *max_element(value, value + k);
  for (int j = 0; j < k; i++, j++) {
    re += len * (i + 1);
  }
  cout << re;
  return 0;
}
