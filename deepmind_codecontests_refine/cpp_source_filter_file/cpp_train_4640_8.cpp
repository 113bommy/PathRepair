#include <bits/stdc++.h>
using namespace std;
long long int expo_fast(long long int a, long long int b) {
  a = a;
  long long int result = 1;
  while (b) {
    if (b & 1) result = (result * a);
    b >>= 1;
    a = (a * a);
  }
  return (result);
}
void take_in(vector<long long int>* arr) {
  for (int i = 0; i < arr->size(); i++) cin >> (*(arr))[i];
}
void disp_arr(vector<long long int>* arr) {
  for (int i = 0; i < arr->size(); i++) cout << (*(arr))[i] << " ";
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n, k, s, t;
  cin >> n >> k >> s >> t;
  multiset<pair<long long int, long long int>> cars;
  vector<long long int> petrol(k);
  for (int i = 0; i < n; i++) {
    long long int a, b;
    cin >> a >> b;
    cars.insert(make_pair(a, b));
  }
  take_in(&petrol);
  petrol.push_back(s);
  sort(petrol.begin(), petrol.end());
  long long int lb = 0, ub = 10;
  long long int ans = -1;
  while (lb <= ub) {
    long long int mid = (lb + ub) / 2;
    long long int prev = 0;
    bool f = true, last = false;
    long long int time = 0;
    for (int i = 0; i < k + 1 && !last; i++) {
      if (petrol[i] == s) {
        last = true;
      }
      if (petrol[i] - prev > mid) {
        f = false;
        break;
      } else {
        long long int x = mid - (petrol[i] - prev);
        long long int norm, acc;
        if (x >= petrol[i] - prev) {
          norm = 0;
          acc = petrol[i] - prev;
        } else
          norm = (petrol[i] - prev) - x, acc = x;
        time += (acc + (norm * 2));
        prev = petrol[i];
        if (time > t) {
          f = false;
          break;
        }
      }
    }
    if (f) {
      ans = mid;
      ub = mid - 1;
    } else
      lb = mid + 1;
  }
  if (ans == -1)
    cout << -1;
  else {
    long long int min_ = -1;
    for (auto p : cars) {
      if (p.second >= ans) {
        if (min_ == -1)
          min_ = p.first;
        else
          min_ = min(min_, p.first);
      }
    }
    cout << min_;
  }
}
