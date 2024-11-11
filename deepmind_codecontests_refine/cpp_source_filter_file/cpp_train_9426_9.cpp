#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  unordered_map<long long int, long long int> m1;
  set<long long int> s1;
  long long int n, k;
  cin >> n >> k;
  long long int arr[n];
  for (long long int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for (long long int i = 0; i < k; i++) {
    m1[arr[i]]++;
    if (m1[arr[i]] > 1) {
      s1.erase(m1[arr[i]]);
    }
    if (m1[arr[i]] == 1) {
      s1.insert(arr[i]);
    }
  }
  if (s1.size() > 0) {
    cout << *(--s1.end()) << endl;
  } else {
    cout << "Nothing\n";
  }
  for (long long int i = k; i < n; i++) {
    m1[arr[i - k]]--;
    m1[arr[i]]++;
    if (m1[arr[i - k]] == 1) {
      s1.insert(arr[i - k]);
    } else if (m1[arr[i - k]] == 0) {
      s1.erase(arr[i - k]);
    }
    if (m1[arr[i]] == 1) {
      s1.insert(arr[i]);
    } else if (m1[arr[i]] > 1) {
      s1.erase(arr[i]);
    }
    if (s1.size() > 0) {
      cout << *(--s1.end()) << endl;
    } else {
      cout << "Nothing\n";
    }
  }
}
