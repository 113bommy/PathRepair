#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, r, avg, res = 0;
  vector<pair<int, int>> marks;
  int temp1, temp2;
  cin >> n >> r >> avg;
  avg *= n;
  for (int i = 0; i < n; i++) {
    cin >> temp1 >> temp2;
    avg -= temp1;
    marks.push_back(make_pair(temp2, r - temp1));
  }
  sort(marks.begin(), marks.end());
  for (int i = 0; avg > 0; i++) {
    long long temp = min(avg, (long long)(marks[i].second));
    res += temp * marks[i].first;
    avg -= temp;
  }
  cout << res << endl;
  return 0;
}
