#include <bits/stdc++.h>
using namespace std;
int64_t check_num(int64_t request) {
  int64_t steps;
  while (request != 1) {
    if ((request % 2 != 0) && (request % 3 != 0) && (request % 5 != 0)) {
      return -1;
    }
    if (request % 2 == 0) {
      request /= 2;
      steps++;
    }
    if (request % 5 == 0) {
      request /= 5;
      steps += 3;
    }
    if (request % 3 == 0) {
      request /= 3;
      steps += 2;
    }
  }
  return steps;
}
int main() {
  uint64_t num_requests;
  cin >> num_requests;
  while (num_requests--) {
    int64_t steps = 0, cur_num;
    cin >> cur_num;
    steps = check_num(cur_num);
    cout << steps << endl;
  }
}
