#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000;
long long x, y;
vector<pair<long long, pair<char, long long> > > ans;
void gen2(int e) {
  long long curr = x;
  for (int i = 0; i < e; i++) {
    ans.push_back(make_pair(curr, make_pair('+', curr)));
    curr *= 2;
  }
  ans.push_back(make_pair(curr, make_pair('^', x)));
  y = curr ^ x;
}
long long gen(long long a, long long c) {
  long long curr = c;
  vector<long long> nums;
  nums.push_back(curr);
  for (long long i = 0; (1LL << i) <= a; i++) {
    ans.push_back(make_pair(curr, make_pair('+', curr)));
    curr *= 2;
    nums.push_back(curr);
  }
  curr = 0;
  for (long long i = 0; (1LL << i) <= a; i++) {
    if ((1 << i) & a) {
      if (curr == 0) {
        ans.push_back(make_pair(x, make_pair('+', nums[i])));
      } else {
        ans.push_back(make_pair(curr, make_pair('+', nums[i])));
      }
      curr += nums[i];
    }
  }
  return curr;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> x;
  int e = 0;
  long long curr = 1;
  while (2 * curr <= x) {
    e++;
    curr *= 2;
  }
  gen2(e);
  long long fa = -1;
  long long fb = -1;
  for (long long b = 0; b < x; b++)
    if ((1 + b * y) % x == 0) {
      long long a = (1 + b * y) / x;
      if (a * x == 1 + b * y) {
        fa = a;
        fb = b;
        break;
      }
    }
  long long ax = gen(fa, x);
  long long by = gen(fb, y);
  if (by % 2 == 0) {
    ans.push_back(make_pair(ax, make_pair('^', by)));
  } else {
    ans.push_back(make_pair(by, make_pair('+', x)));
    ans.push_back(make_pair(ax, make_pair('+', x)));
    ans.push_back(make_pair(by + x, make_pair('^', ax + x)));
  }
  cout << ans.size() << "\n";
  for (auto it : ans) {
    cout << it.first << " " << it.second.first << " " << it.second.second
         << "\n";
  }
}
