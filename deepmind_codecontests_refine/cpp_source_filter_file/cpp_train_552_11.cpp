#include <bits/stdc++.h>
using namespace std;
template <class T>
inline std::string to_string(const T& t) {
  std::stringstream ss;
  ss << t;
  return ss.str();
}
template <class T>
inline long long to_longlong(const T& t) {
  std::stringstream ss;
  long long val;
  ss.str(t);
  ss >> val;
  return val;
}
int main() {
  pair<int, int> arr[100];
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> arr[i].first >> arr[i].second;
  }
  sort(arr, arr + n);
  reverse(arr, arr + n);
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (arr[i].first == arr[j].first && arr[j].second < arr[j].first)
        swap(arr[i], arr[j]);
    }
  }
  int sum = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i].first == arr[k - 1].first && arr[i].second == arr[k - 1].second)
      sum++;
  }
  cout << sum << endl;
  return 0;
}
