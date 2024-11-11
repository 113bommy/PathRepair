#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  int n, k, i, j, q, count, count1 = 0, a, b, c;
  cin >> n >> k;
  vector<int> v1;
  vector<int> v2;
  vector<int>::iterator it;
  for (i = 0; i < n; i++) {
    cin >> q;
    v1.push_back(q);
    v2.push_back(-1);
  }
  for (i = 0; i < n; i++) {
    count = 1;
    for (j = i + 1; j < n; j++) {
      if (v1[i] == v1[j]) {
        count++;
        v2[j] = 0;
      }
    }
    if (v2[i] != 0) {
      v2[i] = count;
      count1++;
    }
  }
  it = std::max_element(v2.begin(), v2.end());
  a = (*it) / k;
  b = (*it) % k;
  if (b == 0) {
    c = count1 * k * a;
  } else if (b != 0) {
    c = (count1 * k * (a + 1));
  }
  cout << (c - n) << endl;
}
