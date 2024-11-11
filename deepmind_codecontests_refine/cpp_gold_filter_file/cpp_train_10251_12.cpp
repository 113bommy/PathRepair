#include <bits/stdc++.h>
using namespace std;
vector<char> v;
pair<int, int> p;
map<int, int> m;
deque<int> d;
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n;
  cin >> n;
  if (n % 2 == 0)
    cout << n / 2 << endl;
  else
    cout << -1 * (n + 1) / 2 << endl;
  return 0;
}
