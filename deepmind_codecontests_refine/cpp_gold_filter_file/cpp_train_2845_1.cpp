#include <bits/stdc++.h>
using namespace std;
using namespace std;
vector<int> prim;
int lamp[1000005];
int woke[1000001];
vector<int> get(int x) {
  vector<int> wow;
  int i = 2;
  while (i * i <= x) {
    if (x % i == 0) {
      x = x / i;
      wow.push_back(i);
    } else {
      i++;
    }
  }
  wow.push_back(x);
  return wow;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  memset(lamp, (-1), sizeof(lamp));
  memset(woke, (-1), sizeof(woke));
  cin >> n >> k;
  for (int tc = 1; tc <= k; tc++) {
    char c;
    int x;
    cin >> c >> x;
    if (c == '-') {
      if (lamp[x] == -1) {
        cout << "Already off" << endl;
      } else {
        cout << "Success" << endl;
        vector<int> tmp;
        tmp = get(x);
        for (int i = 0; i <= (int)tmp.size() - 1; i++) {
          woke[tmp[i]] = -1;
        }
        lamp[x] = -1;
      }
    } else if (c == '+') {
      if (lamp[x] == -1) {
        vector<int> tmp;
        tmp = get(x);
        int cnfl;
        bool ya = false;
        for (int i = 0; i <= (int)tmp.size() - 1; i++) {
          if (woke[tmp[i]] != -1) {
            ya = true;
            cnfl = woke[tmp[i]];
            break;
          }
        }
        if (ya) {
          cout << "Conflict with " << cnfl << endl;
        } else {
          cout << "Success" << endl;
          for (int i = 0; i <= (int)tmp.size() - 1; i++) woke[tmp[i]] = x;
          lamp[x] = 0;
        }
      } else if (lamp[x] == 0) {
        cout << "Already on" << endl;
      }
    }
  }
  return 0;
}
