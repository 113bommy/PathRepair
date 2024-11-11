#include <bits/stdc++.h>
using namespace std;
const long long N = 31625;
int arr[N];
int arr2[N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int x = 1;
  map<int, int> mp;
  arr[1] = 1;
  for (int i = 2; i <= 31624; i++) {
    arr[i] = arr[i - 1] + x;
    mp[arr[i]] = i;
    x += 2;
  }
  arr2[1] = 1;
  x = 3;
  mp[1] = 1;
  for (int i = 2; i <= 31623; i++) {
    arr2[i] = arr2[i - 1] + x;
    mp[arr2[i]] = i;
    x += 2;
  }
  int t;
  cin >> t;
  while (t--) {
    int a;
    cin >> a;
    int b = sqrt(a);
    int xxx = mp.lower_bound(a)->first;
    int yyy = mp.lower_bound(a)->second;
    if (xxx == a) {
      if (b * b == a)
        cout << yyy << " " << 1 << endl;
      else
        cout << 1 << " " << yyy << endl;
    } else if (a <= xxx && a >= (xxx - yyy))
      cout << yyy << " " << xxx - a + 1 << endl;
    else {
      xxx = xxx - (yyy * 2 - 2);
      cout << a - xxx + 1 << " " << mp.lower_bound(xxx)->second << endl;
    }
  }
  return 0;
}
