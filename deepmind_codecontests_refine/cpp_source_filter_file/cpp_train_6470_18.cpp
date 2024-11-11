#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  string s;
  cin >> s;
  long long cnt = 0;
  vector<long long> v;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '8') {
      cnt++;
      v.push_back(i);
    }
  }
  if (cnt == 0)
    puts("NO");
  else {
    long long mid = ((n - 10)) / 2;
    if (cnt < mid)
      puts("NO");
    else {
      long long sum = 0;
      for (int i = 1; i < v.size(); i++) {
        sum += ((v[i] - v[i - 1]) - 1);
      }
      if (sum > mid)
        puts("NO");
      else
        puts("YES");
    }
  }
  return 0;
}
