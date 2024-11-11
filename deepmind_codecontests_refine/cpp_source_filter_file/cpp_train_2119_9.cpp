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
  long long n, d;
  cin >> n >> d;
  long long a, b;
  cin >> a >> b;
  vector<pair<long long, int>> data;
  for (int i = 0; i < n; i++) {
    long long x, y;
    cin >> x >> y;
    data.push_back({x * a + y * b, i + 1});
  }
  sort(data.begin(), data.end());
  int answer = 0;
  for (int i = 0; i < n; i++) {
    if (d - data[i].first > 0) {
      d -= data[i].first;
      answer++;
    }
  }
  cout << answer << endl;
  for (int i = 0; i < answer; i++) cout << data[i].second << " ";
  return 0;
}
