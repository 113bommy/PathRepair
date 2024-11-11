#include <bits/stdc++.h>
using namespace std;
vector<int> make_reverse_range(int from, int to) {
  vector<int> res;
  int x = to;
  while (x != from - 1) {
    res.push_back(x);
    x--;
  }
  return res;
}
vector<int> join_vectors(vector<int> a, vector<int> b) {
  vector<int> res = a;
  for (int i = 0; i < b.size(); i++) {
    res.push_back(b[i]);
  }
  return res;
}
vector<int> solve(int n) {
  vector<int> empty;
  vector<int> zero;
  zero.push_back(0);
  vector<int> one;
  one.push_back(1);
  if (n < 0) return empty;
  if (n == 0) return zero;
  int clpw = 1;
  while (clpw <= n) {
    clpw *= 2;
  }
  clpw--;
  int small = clpw - n;
  return join_vectors(solve(small - 1), make_reverse_range(small, n));
}
int main() {
  int n;
  cin >> n;
  vector<int> solution = solve(n);
  long long count_beauty = 0;
  for (int i = 0; i < solution.size(); i++) {
    count_beauty += i ^ solution[i];
  }
  cout << count_beauty << endl;
  for (int i = 0; i < solution.size(); i++) {
    cout << solution[i];
    if (i != solution.size() - 1) {
      cout << " ";
    }
  }
  cout << endl;
  return 0;
}
