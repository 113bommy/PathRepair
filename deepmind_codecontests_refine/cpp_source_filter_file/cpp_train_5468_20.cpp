#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]) {
  int nums, managers;
  cin >> nums >> managers;
  list<long> numbers;
  stack<pair<int, int>> queries;
  stack<long> finalList;
  int orderings[nums + 1];
  fill(orderings, orderings + nums + 1, 0);
  int num;
  for (int i = 0; i < nums; i++) {
    cin >> num;
    numbers.push_back(num);
  }
  int ordering, r;
  while (managers--) {
    cin >> ordering;
    cin >> r;
    queries.push({ordering, r});
  }
  int biggestSoFar = -1;
  while (!queries.empty()) {
    if (queries.top().second >= biggestSoFar) {
      orderings[queries.top().second - 1] = queries.top().first;
      biggestSoFar = queries.top().second;
    }
    queries.pop();
  }
  bool sorted = false;
  int lastOrder = 0;
  for (int prefix = nums - 1; prefix >= 0; prefix--) {
    if (orderings[prefix] == 0) {
      if (lastOrder != 2) {
        finalList.push(numbers.back());
        numbers.pop_back();
      } else {
        finalList.push(numbers.front());
        numbers.pop_front();
      }
    } else {
      if (!sorted) {
        numbers.sort();
        sorted = true;
      }
      if (orderings[prefix] == 1) {
        finalList.push(numbers.back());
        numbers.pop_back();
      } else {
        finalList.push(numbers.front());
        numbers.pop_front();
      }
      lastOrder = orderings[prefix];
    }
  }
  cout << finalList.top();
  finalList.pop();
  while (!finalList.empty()) {
    cout << " " << finalList.top();
    finalList.pop();
  }
  return 0;
}
