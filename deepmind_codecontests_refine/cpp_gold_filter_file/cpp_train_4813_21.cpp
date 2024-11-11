#include <bits/stdc++.h>
using namespace std;
using i8 = char;
using ui8 = unsigned char;
using i16 = short;
using u16 = unsigned short;
using i32 = int;
using ui32 = unsigned int;
using i64 = long long int;
using ui64 = unsigned long long int;
void task();
const int N = 4e4 + 10;
vector<int> d[N];
int main() {
  srand(time(0));
  ios_base::sync_with_stdio(0);
  for (int i = 1; i < N; ++i) {
    for (int j = 1; j * i < N; ++j) {
      d[i * j].push_back(i);
    }
  }
  int t = 1;
  cin >> t;
  while (t--) {
    task();
  }
  return 0;
}
void task() {
  int a, b, c;
  cin >> a >> b >> c;
  int ans[3];
  int bestAns = 1e9;
  for (int x = 1; x < 2e4 + 10; ++x) {
    int curAns = 0;
    curAns += abs(b - x);
    int curAnsArr[3];
    curAnsArr[1] = x;
    auto it = upper_bound((d[x].begin()), (d[x].end()), a);
    if (it == d[x].end()) {
      --it;
    }
    if (it != d[x].begin()) {
      if (abs(*(it - 1) - a) < abs(*it - a)) {
        --it;
      }
    }
    curAns += abs(*it - a);
    curAnsArr[0] = *it;
    if (c < x) {
      curAns += abs(x - c);
      curAnsArr[2] = x;
    } else if (c % x == 0) {
      curAnsArr[2] = c;
    } else {
      if (c % x < x - c % x) {
        curAns += c % x;
        curAnsArr[2] = c - (c % x);
      } else {
        curAns += x - c % x;
        curAnsArr[2] = c + (x - c % x);
      }
    }
    if (curAns < bestAns) {
      bestAns = curAns;
      ans[0] = curAnsArr[0];
      ans[1] = curAnsArr[1];
      ans[2] = curAnsArr[2];
    }
  }
  cout << bestAns << endl;
  cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << endl;
}
