#include <bits/stdc++.h>
const int dx8[] = {1, -1, 0, 0, 1, -1, 1, -1};
const int dy8[] = {0, 0, 1, -1, 1, -1, -1, 1};
const int dx4[] = {1, -1, 0, 0};
const int dy4[] = {0, 0, 1, -1};
using namespace std;
void task() {
  vector<int> a;
  int n, k;
  cin >> n >> k;
  cout << "and 1 2" << endl;
  int a_and_b, a_and_c, c_and_b;
  int a_or_b, a_or_c, c_or_b;
  cin >> a_and_b;
  cout << "and 1 3" << endl;
  cin >> a_and_c;
  cout << "and 2 3" << endl;
  cin >> c_and_b;
  cout << "or 1 2" << endl;
  cin >> a_or_b;
  cout << "or 1 3" << endl;
  cin >> a_or_c;
  cout << "or 2 3" << endl;
  cin >> c_or_b;
  int ab = a_and_b + a_or_b;
  int ac = a_and_c + a_or_c;
  int bc = c_and_b + c_or_b;
  int ref = ab + ac - bc;
  a.push_back(ref);
  a.push_back(ac - ref);
  a.push_back(ab - ref);
  for (int i = 4; i <= n; i++) {
    int nd, r;
    cout << "and 1 " << i << endl;
    cin >> nd;
    cout << "or 1 " << i << endl;
    cin >> r;
    int s = nd + r;
    a.push_back(s - ref);
  }
  sort((a).begin(), (a).end());
  cout << "finish " << a[k - 1] << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int TT = 1;
  while (TT--) {
    task();
  }
  return 0;
}
