#include <bits/stdc++.h>
using namespace std;
static const double EPS = 1e-9;
template <class T>
inline T sq(T a) {
  return a * a;
}
const int INF = 1 << 29;
string in[] = {"pushBack", "pushStack", "pushQueue", "pushFront"};
string out[] = {"popStack", "popQueue", "popFront"};
int x[100010];
int ope[100010];
int main() {
  int n;
  cin >> n;
  priority_queue<pair<int, int> > q;
  for (int i = 0; i < (n); i++) {
    cin >> x[i];
    if (x[i]) {
      q.push(make_pair(x[i], i));
    } else {
      ope[i] = min((int)q.size(), 3);
      for (int j = 0; j < (ope[i]); j++) {
        ope[q.top().second] = j + 1;
        q.pop();
      }
      q = priority_queue<pair<int, int> >();
    }
  }
  for (int i = 0; i < (n); i++) {
    if (x[i]) {
      cout << in[ope[i]] << endl;
    } else {
      cout << ope[i];
      for (int j = 0; j < (ope[i]); j++) {
        cout << ' ' << out[j];
      }
      cout << endl;
    }
  }
  return 0;
}
