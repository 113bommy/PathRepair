#include <bits/stdc++.h>
using namespace std;
vector<int> people;
int abs(int x) { return (x > 0) ? x : -x; }
int main() {
  ios_base::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    people.push_back(t);
  }
  sort(people.begin(), people.end());
  reverse(people.begin(), people.end());
  int answer = 0, a, b = 1;
  for (int i = 0; i < people.size(); i += k) {
    a = people[i];
    answer += abs(a - b);
  }
  cout << answer * k << endl;
  return 0;
}
