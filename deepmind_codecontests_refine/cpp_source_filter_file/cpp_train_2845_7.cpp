#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
int door[N];
int occ[N];
std::vector<int> divi[N];
set<int> multiple[N];
void seive() {
  for (int i = 2; i < N; i++) {
    for (int j = i; j < N; j += i) divi[j].push_back(i);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  seive();
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < q; i++) {
    char ch;
    cin >> ch;
    int no;
    cin >> no;
    if (ch == '+') {
      if (door[no] == 1) {
        cout << "Already on";
      } else {
        bool fl = 0;
        for (auto i : divi[no]) {
          if (occ[i] == 1) {
            cout << "conflict with " << *(multiple[i].begin());
            fl = 1;
            break;
          }
        }
        if (fl == 0) {
          cout << "Success";
          for (auto i : divi[no]) {
            occ[i]++;
            multiple[i].insert(no);
          }
          door[no] = 1;
        }
      }
    } else {
      if (door[no] == 1) {
        door[no] = 0;
        for (auto i : divi[no]) {
          occ[i]--;
          multiple[i].erase(no);
        }
        cout << "Success";
      } else {
        cout << "Already off";
      }
    }
    cout << "\n";
  }
  return 0;
}
