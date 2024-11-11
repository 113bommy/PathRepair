#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  int size;
  cin >> size;
  vector<int> mem(size);
  vector<int> allocSize(1);
  vector<int> ps(1);
  for (int qqq = 1; qqq < t + 1; ++qqq) {
    string op;
    cin >> op;
    ;
    if (op == "alloc") {
      int reqSz;
      cin >> reqSz;
      ;
      int foundP = -1;
      int accSz = 0;
      for (int i = 0; i < size - 1 + 1; ++i)
        if (mem[i] == 0) {
          accSz++;
          if (accSz == reqSz) {
            foundP = i - reqSz + 1;
            break;
          }
        } else {
          accSz = 0;
          i += allocSize[mem[i]] - 1;
        }
      if (foundP == -1) {
        cout << "NULL";
      } else {
        allocSize.push_back(reqSz);
        mem[foundP] = ps.size();
        ps.push_back(foundP);
        cout << mem[foundP];
      }
      cout << '\n';
    } else if (op == "erase") {
      int id;
      cin >> id;
      ;
      if (id < 1 || id >= ps.size() || ps[id] == -1) {
        cout << "ILLEGAL_ERASE_ARGUMENT\n";
      } else {
        mem[ps[id]] = 0;
        ps[id] = -1;
      }
    } else {
      int from = 0;
      int to = 0;
      while (from < size) {
        if (mem[from] == 0)
          from++;
        else {
          int id = mem[from];
          mem[from] = 0;
          mem[to] = id;
          ps[id] = to;
          from += allocSize[id];
          to += allocSize[id];
        }
      }
    }
  }
}
