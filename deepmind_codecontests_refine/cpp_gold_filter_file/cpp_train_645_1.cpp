#include <bits/stdc++.h>
using namespace std;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cout << *it << " = " << a << endl;
  err(++it, args...);
}
const int mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int n;
  cin >> n;
  vector<pair<int, int> > vect(n);
  for (int i = 0; i < n; i++) cin >> vect[i].first;
  for (int i = 0; i < n; i++) cin >> vect[i].second;
  sort(vect.begin(), vect.end());
  multiset<int> st;
  long long i = 0, temp, sum = 0, ans = 0;
  while (true) {
    if (st.size() == 0 && i == n) return cout << ans, 0;
    if (st.size() == 0) temp = vect[i].first;
    for (; vect[i].first == temp; i++) {
      st.insert(vect[i].second);
      sum += vect[i].second;
    }
    sum -= (*st.rbegin());
    ans += sum;
    st.erase(--st.end());
    temp++;
  }
}
