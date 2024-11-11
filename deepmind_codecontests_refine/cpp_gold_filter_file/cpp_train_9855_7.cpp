#include <bits/stdc++.h>
using namespace std;
long long n;
vector<long long> a;
void lucky(long long num, int f, int s) {
  if (num > 100000000000ll) return;
  if (f == s) a.push_back(num);
  lucky(num * 10 + 4, f + 1, s);
  lucky(num * 10 + 7, f, s + 1);
}
int main() {
  cin >> n;
  lucky(0, 0, 0);
  sort(a.begin(), a.end());
  int i = 0;
  for (; a[i] < n; i++)
    ;
  cout << a[i];
}
