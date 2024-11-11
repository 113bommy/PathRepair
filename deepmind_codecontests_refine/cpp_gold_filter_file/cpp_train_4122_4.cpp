#include <bits/stdc++.h>
template <typename T>
using min_heap = std::priority_queue<T, std::vector<T>, std::greater<T>>;
template <typename T>
using max_heap = std::priority_queue<T, std::vector<T>, std::less<T>>;
using namespace std;
vector<int> digits(int n) {
  vector<int> v;
  if (n == 0) {
    v.push_back(0);
    return v;
  }
  while (n > 0) {
    v.push_back(n % 10);
    n /= 10;
  }
  reverse(v.begin(), v.end());
  return v;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string prog = "++>+++><[<+>-]<+++++++++++++++++++++++++++++++++++++++++++";
  string in;
  cin >> in;
  int res = 0, curr = 0;
  bool negative = false;
  for (auto c : in) {
    if (c == '+') {
      int num = curr * (negative ? -1 : 1);
      res += num;
      curr = 0;
      negative = false;
    } else if (c == '-') {
      int num = curr * (negative ? -1 : 1);
      res += num;
      curr = 0;
      negative = true;
    } else {
      curr = 10 * curr + c - '0';
    }
  }
  int num = curr * (negative ? -1 : 1);
  res += num;
  for (int d : digits(res)) {
    for (int i = (0); i < (d); i++) prog += "+";
    prog += ".";
    for (int i = (0); i < (d); i++) prog += "-";
  }
  cout << prog << "\n";
  return 0;
}
