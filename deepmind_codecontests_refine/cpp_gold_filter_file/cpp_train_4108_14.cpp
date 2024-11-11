#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  vector<int> vec;
  vec.resize(N);
  for (int i = 0; i < N; i++) cin >> vec[i];
  sort(vec.begin(), vec.end());
  vector<int64_t> vec2;
  int iCurrent = vec[0];
  int64_t iCurSum = 0;
  for (int i = 0; i < N; i++) {
    if (vec[i] > iCurrent)
      for (int j = 0; j < min(2, vec[i] - iCurrent); j++) {
        vec2.push_back(iCurSum);
        iCurSum = 0;
      }
    iCurSum += vec[i];
    iCurrent = vec[i];
  }
  vec2.push_back(iCurSum);
  vector<int64_t> opt;
  opt.resize(vec2.size());
  if (vec2.size() == 1) {
    cout << vec2[0];
    return 0;
  }
  if (vec2.size() == 2) {
    cout << max(vec2[0], vec2[1]);
    return 0;
  }
  opt[0] = vec2[0];
  opt[1] = vec2[1];
  opt[2] = vec2[2] + vec2[0];
  for (int i = 3; i < opt.size(); i++)
    opt[i] = vec2[i] + max(opt[i - 2], opt[i - 3]);
  vector<int64_t> realopt;
  opt.resize(vec2.size());
  cout << max(opt[opt.size() - 1], opt[opt.size() - 2]);
  cin.get();
}
