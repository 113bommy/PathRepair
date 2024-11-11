#include <bits/stdc++.h>
using namespace std;
int mapping[200001];
int main(int narg, char **arg) {
  int h, m, n;
  cin >> h >> m >> n;
  int hh = 0, occup_size = 0;
  while (true) {
    mapping[hh] = occup_size;
    hh += m;
    hh %= h;
    occup_size++;
    if (!hh) break;
  }
  int n_occup = h / occup_size;
  map<int, int> occup[n_occup];
  for (int i = 0; i < occup_size; i++) mapping[i] = mapping[i * n_occup];
  int counter = 0;
  map<int, pair<int, int> > positions;
  for (int i = 0; i < n; i++) {
    char op;
    int id, hash_value;
    cin >> op >> id;
    int i_occup, i_start;
    if (op == '+') {
      cin >> hash_value;
      i_occup = hash_value % n_occup;
      i_start = mapping[hash_value / n_occup];
      while (true) {
        map<int, int>::iterator it = occup[i_occup].upper_bound(i_start);
        if (it == occup[i_occup].begin()) {
          occup[i_occup][i_start] = i_start;
          it = occup[i_occup].begin();
        } else {
          --it;
          if (it->second >= i_start - 1) {
            if (it->second == occup_size - 1) {
              counter += occup_size - i_start;
              i_start = 0;
              continue;
            }
            it->second++;
            counter += it->second - i_start;
            i_start = it->second;
          } else {
            it = occup[i_occup].insert(make_pair(i_start, i_start)).first;
          }
        }
        map<int, int>::iterator it2 = it;
        ++it2;
        if (it2 != occup[i_occup].end()) {
          if (it->second + 1 == it2->first) {
            it->second = it2->second;
            occup[i_occup].erase(it2);
          }
        }
        break;
      }
      positions[id] = make_pair(i_occup, i_start);
    } else {
      pair<int, int> p = positions[id];
      i_occup = p.first;
      i_start = p.second;
      positions.erase(id);
      map<int, int>::iterator it = occup[i_occup].upper_bound(i_start);
      --it;
      if (it->first == i_start) {
        int last = it->second;
        occup[i_occup].erase(it);
        if (last != i_start) occup[i_occup][i_start + 1] = last;
      } else if (it->second == i_start)
        it->second--;
      else {
        int last = it->second;
        it->second = i_start - 1;
        occup[i_occup][i_start + 1] = last;
      }
    }
  }
  cout << counter << endl;
  return 0;
}
