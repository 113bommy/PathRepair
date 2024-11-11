#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int arr[3] = {0};
  vector<pair<int, int> > v;
  for (int i = 0; i < 3; i++) {
    string s;
    cin >> s;
    if (s[1] == '>') {
      arr[s[0] - 'A']++;
    } else {
      arr[s[2] - 'A']++;
    }
  }
  for (int i = 0; i < 3; i++) {
    v.push_back(make_pair(arr[i], i));
  }
  sort(v.begin(), v.end());
  sort(arr, arr + 3);
  for (int i = 0; i < 3; i++) {
    if (arr[i] != i) {
      cout << "Impossible" << endl;
      return 0;
    }
  }
  for (int i = 0; i < 3; i++) {
    cout << char(v[i].second + 'A');
  }
  return 0;
}
