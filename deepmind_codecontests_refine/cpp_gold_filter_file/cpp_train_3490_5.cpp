#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, q;
  cin >> n >> k >> q;
  bool full = false;
  int counter = 0;
  vector<int> t(n);
  vector<int> qu(k, -1);
  for (int i = 0; i < n; i++) {
    cin >> t[i];
  }
  for (int i = 0; i < q; i++) {
    int type, id;
    cin >> type >> id;
    id--;
    if (type == 1) {
      if (counter < k) {
        qu[counter] = id;
        counter++;
      } else {
        int index = 0;
        for (int j = 0; j < k; j++) {
          if (t[qu[index]] > t[qu[j]]) index = j;
        }
        if (t[id] > t[qu[index]]) qu[index] = id;
      }
    } else {
      bool is_in = false;
      for (int j = 0; j < k; j++) {
        if (qu[j] == id) is_in = true;
      }
      if (is_in)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    }
  }
}
