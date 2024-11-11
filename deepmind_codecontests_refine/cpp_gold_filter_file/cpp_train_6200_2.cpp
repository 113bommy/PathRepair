#include <bits/stdc++.h>
using namespace std;
int main() {
  long long max_val = 2 * (long long)1e9;
  long long x, power_of_two;
  x = 1;
  power_of_two = 1;
  while (power_of_two <= max_val) {
    x++;
    power_of_two *= 2;
  }
  long long count = 0;
  int n;
  cin >> n;
  map<int, int> a_map;
  int power_two = 1;
  int arr[100005];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    a_map[arr[i]]++;
  }
  for (int i = 0; i < n; i++) {
    for (int x = 0; x < 32; x++) {
      double diff = pow(2.0, x) - arr[i];
      if (a_map.count(int(diff))) {
        if (diff != arr[i])
          count += a_map[int(diff)];
        else
          count = count + a_map[int(diff)] - 1;
      }
    }
  }
  cout << count / 2 << endl;
  return 0;
}
