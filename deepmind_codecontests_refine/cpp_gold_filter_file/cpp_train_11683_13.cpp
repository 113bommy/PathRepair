#include <bits/stdc++.h>
using namespace std;
const int LIMIT = 100;
const double ESP = 10e-9;
const int INF = 1000000000;
char buffer[100010];
int main(int argc, const char *argv[]) {
  priority_queue<pair<string, int>, vector<pair<string, int> >,
                 greater<pair<string, int> > >
      Q;
  pair<string, int> next;
  long long k, size;
  string line;
  cin >> line >> k;
  size = line.length();
  if (k > (size * size + size) / 2) {
    cout << "No such line." << endl;
  } else {
    for (int i = 0; i < size; i++) Q.push(make_pair(string(1, line[i]), i));
    while (k--) {
      next = Q.top();
      if (k == 0) {
        cout << next.first << endl;
        break;
      }
      Q.pop();
      if (next.second + 1 < size) {
        next.first += line[++next.second];
        Q.push(next);
      }
    }
  }
  return 0;
}
