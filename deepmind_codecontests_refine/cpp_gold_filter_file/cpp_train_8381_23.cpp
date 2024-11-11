#include <bits/stdc++.h>
using namespace std;
string s;
long long countDivisbleby4(string s1) {
  long long n = s1.size();
  long long count = 0;
  for (long long i = 0; i < n; ++i)
    if (s1[i] == '4' || s1[i] == '8' || s1[i] == '0') count++;
  for (long long i = 0; i < n - 1; ++i) {
    long long h = (s1[i] - '0') * 10 + (s1[i + 1] - '0');
    if (h % 4 == 0) count = count + i + 1;
  }
  return count;
}
int main() {
  cin >> s;
  cout << countDivisbleby4(s);
  return 0;
}
