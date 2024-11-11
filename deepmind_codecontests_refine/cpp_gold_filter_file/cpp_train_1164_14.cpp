#include <bits/stdc++.h>
using namespace std;
vector<long long int> v;
int main() {
  int n, k;
  cin >> n >> k;
  string str;
  cin >> str;
  for (int i = 0; i < str.size() - 1; i++) {
    if (!k) break;
    if (str[i] == '4' && str[i + 1] == '7') {
      k--;
      if (i && (i % 2 == 1) && str[i - 1] == '4') {
        if (k % 2 == 0) str[i] = '7';
        k = 0;
      } else if (i % 2 == 1)
        str[i] = '7';
      else
        str[i + 1] = '4';
    }
  }
  cout << str << endl;
  return 0;
}
