#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<long long> vec(n);
  for (int i = 0; i < n; i++) {
    cin >> vec[i];
  }
  long long total_clicks = 0;
  long long prev_clicks = 1;
  for (int i = 0; i < vec.size(); i++) {
    total_clicks += 1;
    total_clicks += (vec[i] - 1) * (i + 1);
  }
  cout << total_clicks << endl;
}
