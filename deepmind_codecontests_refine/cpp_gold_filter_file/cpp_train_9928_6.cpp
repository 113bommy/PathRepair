#include <bits/stdc++.h>
using namespace std;
long long n;
unordered_set<long long> s;
void cal(char a, char b) {
  long long digit = 0;
  long long nn = n;
  while (nn) nn /= 10, digit++;
  for (long long d = 1; d <= digit; d++) {
    long long l = (long long)(1 << d);
    for (long long i = 0; i < l; i++) {
      string temp;
      long long num = 0;
      for (long long j = 0; j < d; j++)
        if (i & (1 << j))
          temp.push_back(a);
        else
          temp.push_back(b);
      num = stoi(temp);
      if (num != 0 && num <= n) s.insert(num);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  long long ans = 0;
  if (n == 1000000000) n--, ans++;
  for (long long i = 0; i < 10; i++)
    for (long long j = i + 1; j <= 9; j++) cal(48 + i, 48 + j);
  cout << s.size() + ans;
}
