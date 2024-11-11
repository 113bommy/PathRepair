#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  long long start_time, end_time, service_time, n;
  cin >> start_time >> end_time >> service_time >> n;
  long long arr[n];
  vector<long long> times;
  times.push_back(start_time);
  times.push_back(end_time - service_time);
  times.push_back(0);
  cin >> arr[0];
  if (arr[0] != 0) {
    times.push_back(arr[0] - 1);
  }
  for (int i = 1; i < n; i++) {
    cin >> arr[i];
    if (arr[i] != arr[i - 1]) {
      times.push_back(arr[i] - 1);
    }
  }
  long long index, ans = 1e18, mytime = 0, waiting_time;
  sort(times.begin(), times.end());
  for (long long &current_time : times) {
    index = upper_bound(arr, arr + n, current_time) - arr;
    waiting_time = start_time + service_time * (index)-current_time;
    if (current_time > end_time - service_time) {
      break;
    }
    if (start_time + service_time * (index) > end_time - service_time) {
      break;
    }
    if (waiting_time < ans) {
      ans = waiting_time;
      mytime = current_time;
    }
  }
  cout << mytime << endl;
  return 0;
}
