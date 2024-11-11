#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
vector<pair<int, int> > A;
int main() {
  int n, last = INF, i = -1;
  cin >> n;
  for (int x = 0, qwert = n; x < qwert; x++) {
    int tmp;
    cin >> tmp;
    if (tmp != last) A.push_back({tmp, x});
    last = tmp;
  }
  for (int x = 1, qwert = ((int)(A).size()) - 1; x < qwert; x++)
    if ((A[x - 1].first < A[x].first) == (A[x].first > A[x + 1].first)) i = x;
  if (i == -1) {
    cout << "0\n";
  } else {
    cout << "3\n";
    cout << A[i - 1].second + 1 << " " << A[i].second + 1 << " "
         << A[i + 1].second + 1 << "\n";
  }
}
