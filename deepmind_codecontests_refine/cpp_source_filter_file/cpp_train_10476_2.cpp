#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  long long int sum[s.length()];
  for (long long int i = 0; i < s.length(); i++) {
    if (s[i] == 'Q') {
      if (i == 0)
        sum[i] = 1;
      else
        sum[i] = 1 + sum[i - 1];
    } else {
      if (i == 0)
        sum[i] = 0;
      else
        sum[i] = sum[i - 1];
    }
  }
  long long int pr = 0;
  for (long long int i = 0; i < s.length() - 1; i++) {
    if (s[i] == 'A') {
      pr += sum[i - 1] * (sum[s.length() - 1] - sum[i]);
    }
  }
  cout << pr << endl;
}
