#include <bits/stdc++.h>
using namespace std;
int find_good(vector<long long int> v, int l) {
  if (l == 1) return 1;
  vector<bool> mark;
  mark.push_back(true);
  mark.push_back(true);
  for (int i = 2; i < l; i++) mark.push_back(v[i] == v[i - 1] + v[i - 2]);
  mark.push_back(false);
  int maxlen = -1, count = 0;
  for (int i = 0; i <= l; i++) {
    if (mark[i]) {
      count++;
    } else {
      maxlen = max(maxlen, count);
      count = 0;
    }
  }
  return maxlen;
}
int main() {
  int num;
  long long int inp;
  vector<long long int> inputs;
  while (scanf("%d", &num) == 1) {
    for (int i = 0; i < num; i++) {
      cin >> inp;
      inputs.push_back(inp);
    }
    cout << find_good(inputs, num) << endl;
    inputs.clear();
  }
}
