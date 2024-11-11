#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n;
  cin >> n;
  long long arr[n];
  for (long long i = 0; i < n; i++) cin >> arr[i];
  long long min = arr[0], ind = 0;
  unordered_map<long long, long long> m;
  for (long long i = 0; i < n; i++) {
    if (arr[i] < min) {
      min = arr[i];
      ind = i + 1;
    }
    m[arr[i]]++;
  }
  if (m[min] > 1)
    cout << "Still Rozdil" << endl;
  else
    cout << ind << endl;
  return 0;
}
