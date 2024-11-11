#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 50;
int arr[N];
int main() {
  int n, m, d;
  cin >> n >> m >> d;
  set<pair<int, int> > st;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    st.insert(make_pair(arr[i], i));
  }
  int day = 0;
  while (!st.empty()) {
    day++;
    int a = st.begin()->first;
    int b = st.begin()->second;
    st.erase(st.begin());
    arr[b] = day;
    auto it = st.upper_bound(make_pair(a + d, 1e9));
    while (it != st.end()) {
      a = it->first;
      b = it->second;
      st.erase(it);
      arr[b] = day;
      it = st.upper_bound(make_pair(a + d, 1e9));
    }
  }
  cout << day << endl;
  for (int i = 0; i < n; ++i) cout << arr[i] << " ";
  return 0;
}
