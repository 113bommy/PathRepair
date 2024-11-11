#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, s;
  cin >> n >> s;
  vector<pair<long long, long long> > data;
  long long result = 0;
  long long tots = 0;
  for (int i = 0; i < n; i++) {
    long long si, ai, bi;
    cin >> si >> ai >> bi;
    data.push_back(make_pair(ai - bi, si));
    result += bi * si;
    tots += si;
  }
  if (tots % s != 0) {
    data.push_back(make_pair(0, s - tots % s));
  }
  sort(data.begin(), data.end());
  long long now_s = 0;
  long long temp_sum = 0;
  for (int i = 0; i < data.size(); i++) {
    long long di = data[i].first;
    long long si = data[i].second;
    if (now_s + si >= s) {
      temp_sum += (s - now_s) * di;
      result = max(result, result + temp_sum);
      temp_sum = 0;
      si -= s - now_s;
      long long t = (long long)(si / s);
      result = max(result, result + t * s * di);
      now_s = si - s * t;
      temp_sum = now_s * di;
    } else {
      temp_sum += si * di;
      now_s += si;
    }
  }
  if (temp_sum > 0) {
    result = max(result, result + temp_sum);
  }
  cout << result << endl;
  return 0;
}
