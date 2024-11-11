#include <bits/stdc++.h>
using namespace std;
vector<long long> lucky;
long long MAX = 1000 * 1000 * 1000;
void gen(long long cur) {
  if (cur > MAX) return;
  lucky.push_back(cur);
  gen(cur * 10 + 4);
  gen(cur * 10 + 7);
}
int main() {
  long long n;
  cin >> n;
  gen(0);
  sort(lucky.begin(), lucky.end());
  for (int i = 0; i < 1025; i++)
    if (lucky[i] == n) {
      cout << i;
      break;
    }
  return 0;
}
