#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, s, d;
  cin >> n >> m >> s >> d;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  vector<string> answer;
  int at = 0;
  int at_index = 0;
  while (true) {
    int run_till;
    if (at_index >= a.size()) {
      run_till = m - at;
      answer.push_back("RUN " + to_string(run_till));
      at = m;
      break;
    } else {
      run_till = a[at_index] - 1 - at;
    }
    if (run_till < s) {
      break;
    } else {
      answer.push_back("RUN " + to_string(run_till));
      at += run_till;
    }
    while (at_index + 1 < a.size() && a[at_index + 1] - a[at_index] < s + 2) {
      at_index++;
    }
    int jump_till = a[at_index] + 1 - at;
    if (jump_till > d) {
      break;
    }
    answer.push_back("JUMP " + to_string(jump_till));
    at += jump_till;
    at_index++;
  }
  if (at == m) {
    for (int i = 0; i < answer.size(); i++) {
      cout << answer[i] << endl;
    }
  } else {
    cout << "IMPOSSIBLE" << endl;
  }
}
