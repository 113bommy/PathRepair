#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::deque;
using std::endl;
using std::map;
using std::max;
using std::min;
using std::multiset;
using std::pair;
using std::queue;
using std::set;
using std::sort;
using std::stack;
using std::string;
using std::vector;
int main() {
  int n;
  cin >> n;
  int cnt[212345] = {
      0,
  };
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    cnt[x] = i + 1;
  }
  int answer = -1;
  int time = n + 1;
  for (int i = 1; i <= 200000; i++) {
    if (cnt[i] > 0 && cnt[i] < time) {
      answer = i;
      time = cnt[i];
    }
  }
  cout << answer;
  return 0;
}
