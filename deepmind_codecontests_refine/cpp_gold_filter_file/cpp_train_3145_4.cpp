#include <bits/stdc++.h>
using namespace std;
int log(int x) {
  if (x <= 1)
    return 0;
  else
    return 1 + log(x >> 1);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int place = 1;
  int curr;
  cin >> curr;
  while (curr != -1) {
    cin >> curr;
    place++;
  }
  vector<int> rest;
  for (int i = 0; i < n - place; i++) {
    cin >> curr;
    rest.push_back(-1 * curr);
  }
  int roundLeft = log(n) - log(place);
  if (roundLeft == 0) {
    return cout << 0 << '\n', 0;
    ;
  }
  long long bribe = rest[rest.size() - 1];
  rest.pop_back();
  roundLeft--;
  vector<int> top;
  make_heap(top.begin(), top.end());
  for (int i = 0; i < roundLeft; i++) {
    for (int j = 0; j < n >> (i + 1); j++) {
      top.push_back(rest.back());
      rest.pop_back();
      push_heap(top.begin(), top.end());
    }
    bribe += top.front();
    pop_heap(top.begin(), top.end());
    top.pop_back();
  }
  return cout << -1 * bribe << '\n', 0;
  ;
}
