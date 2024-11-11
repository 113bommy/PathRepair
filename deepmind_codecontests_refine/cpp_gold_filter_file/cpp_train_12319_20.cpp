#include <bits/stdc++.h>
using namespace std;
inline int toInt(string s) {
  int v;
  istringstream sin(s);
  sin >> v;
  return v;
}
template <class T>
inline string toString(T x) {
  ostringstream sout;
  sout << x;
  return sout.str();
}
template <class T>
inline T sqr(T x) {
  return x * x;
}
const double PI = acos(-1.0);
int memo[1 << 22];
inline int calc(int x) {
  int &res = memo[x];
  if (res > -2) return res;
  for (int i = (0); i < (22); ++i)
    if ((x & (1 << i)) == 0) {
      res = max(res, calc(x | (1 << i)));
    }
  return res;
}
int main(int argc, const char *argv[]) {
  for (int i = (0); i < ((1 << 22)); ++i) memo[i] = -2;
  int N;
  cin >> N;
  vector<int> nums(N);
  for (int i = (0); i < (N); ++i) {
    scanf("%d", &nums[i]);
    memo[nums[i] xor ((1 << 22) - 1)] = nums[i];
  }
  memo[(1 << 22) - 1] = -1;
  for (int i = (0); i < (N); ++i) {
    printf("%d ", calc(nums[i]));
  }
  cout << endl;
  return 0;
}
