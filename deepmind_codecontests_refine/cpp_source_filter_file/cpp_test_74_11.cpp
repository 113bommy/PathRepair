#include <bits/stdc++.h>
using namespace std;
const int max_n = 1e3 + 10, inf = 1000111222;
const int max_sum = 2e6 + 10;
pair<int, int> any_found[max_sum];
int b[max_n];
const bool debug = 0;
const int debug_A = 30;
int debug_buf[max_n];
bool rec(int pos, const vector<int> &b) {
  if (pos == (int)(b.size())) {
    set<int> kek(b.begin(), b.end());
    for (int i = 0; i < pos; i++) {
      for (int j = i + 1; j < pos; j++) {
        kek.erase(debug_buf[i] + debug_buf[j]);
      }
    }
    return kek.empty();
  }
  for (int i = -debug_A; i <= debug_A; i++) {
    debug_buf[pos] = i;
    if (rec(pos + 1, b)) {
      return 1;
    }
  }
  return 0;
}
bool naive(vector<int> b) { return rec(0, b); }
bool ok_my_ans(vector<int> my_ans, vector<int> b) {
  if ((int)(my_ans.size()) != (int)(b.size())) {
    return 0;
  }
  set<int> kek(b.begin(), b.end());
  for (int i = 0; i < (int)(my_ans.size()); i++) {
    for (int j = i + 1; j < (int)(my_ans.size()); j++) {
      kek.erase(my_ans[i] + my_ans[j]);
    }
  }
  return kek.empty();
}
void my_assert(bool a) {
  if (!a) {
    cout << "VERY BAD"
         << "\n";
    exit(0);
  }
}
bool get_bit(int mask, int bit) { return (mask >> bit) & 1; }
int main() {
  double start = clock();
  srand(29982);
start_of_program:;
  static int test_id = 0;
  if (debug) {
    cout << test_id++ << " +++ "
         << "\n";
  }
  int n;
  if (debug) {
    n = 5;
    for (int i = 0; i < 250; i++) {
      any_found[i] = make_pair(0, 0);
    }
    cout << n << "\n";
  } else {
    cin >> n;
  }
  bool any = 0;
  vector<int> odds;
  for (int i = 1; i < 30; i += 2) {
    odds.push_back(i);
  }
  random_shuffle(odds.begin(), odds.end());
  for (int i = 0; i < n; i++) {
    if (debug) {
      if (1 || test_id % 2 == 0) {
        b[i] = odds.back();
        odds.pop_back();
      } else {
        b[i] = rand() % 15;
      }
      cout << b[i] << " ";
    } else {
      cin >> b[i];
    }
    any |= (b[i] % 2 == 0);
  }
  if (debug) {
    cout << "\n";
  }
  sort(b, b + n);
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (b[i] == b[j]) {
        cout << "YES"
             << "\n";
        cout << 0 << " " << b[i] << " ";
        for (int k = 0; k < n; k++) {
          if (k != i && k != j) {
            cout << b[k] + 1 << " ";
          }
        }
        cout << "\n";
        if (debug) {
          vector<int> my_ans;
          my_ans.push_back(0);
          my_ans.push_back(b[i]);
          for (int k = 0; k < n; k++) {
            if (k != i && k != j) {
              my_ans.push_back(b[k]);
            }
          }
          my_assert(ok_my_ans(my_ans, {b, b + n}));
          my_assert(naive({b, b + n}));
          goto start_of_program;
        } else {
          return 0;
        }
      }
    }
  }
  if (n == 2) {
    cout << "NO"
         << "\n";
    if (debug) {
      my_assert(!naive({b, b + n}));
      goto start_of_program;
    } else {
      return 0;
    }
  }
  if (n == 3) {
    int sum = b[0] + b[1] + b[2];
    if (sum % 2 == 0) {
      cout << "YES"
           << "\n";
      cout << sum / 2 - b[0] << " " << sum / 2 - b[1] << " " << sum / 2 - b[2]
           << "\n";
      if (debug) {
        vector<int> my_ans;
        my_ans.push_back(sum / 2 - b[0]);
        my_ans.push_back(sum / 2 - b[1]);
        my_ans.push_back(sum / 2 - b[2]);
        my_assert(ok_my_ans(my_ans, {b, b + n}));
        my_assert(naive({b, b + n}));
        goto start_of_program;
      } else {
        return 0;
      }
    } else {
      cout << "NO"
           << "\n";
      if (debug) {
        my_assert(!naive({b, b + n}));
        goto start_of_program;
      } else {
        return 0;
      }
    }
  }
  if (any) {
    vector<int> poses_even;
    vector<int> poses_odd;
    for (int i = 0; i < n; i++) {
      if (b[i] % 2 == 0) {
        poses_even.push_back(i);
      } else {
        poses_odd.push_back(i);
      }
    }
    my_assert(!poses_even.empty());
    int p1 = -1;
    int p2 = -1;
    int p3 = -1;
    if ((int)(poses_odd.size()) >= 2) {
      p1 = poses_even[0];
      p2 = poses_odd[0];
      p3 = poses_odd[1];
    } else {
      my_assert((int)(poses_even.size()) >= 3);
      p1 = poses_even[0];
      p2 = poses_even[1];
      p3 = poses_even[2];
    }
    int sum = b[p1] + b[p2] + b[p3];
    my_assert(sum % 2 == 0);
    cout << "YES"
         << "\n";
    cout << sum / 2 - b[p1] << " " << sum / 2 - b[p2] << " " << sum / 2 - b[p3]
         << " ";
    for (int i = 0; i < n; i++) {
      if (i != p1 && i != p2 && i != p3) {
        cout << b[i] - (sum / 2 - b[p1]) << " ";
      }
    }
    cout << "\n";
    if (debug) {
      vector<int> my_ans;
      my_ans.push_back(sum / 2 - b[p1]);
      my_ans.push_back(sum / 2 - b[p2]);
      my_ans.push_back(sum / 2 - b[p3]);
      for (int i = 0; i < n; i++) {
        if (i != p1 && i != p2 && i != p3) {
          my_ans.push_back(b[i] - (sum / 2 - b[p1]));
        }
      }
      my_assert(ok_my_ans(my_ans, {b, b + n}));
      my_assert(naive({b, b + n}));
      goto start_of_program;
    } else {
      return 0;
    }
  }
  if (debug) {
    cout << "here"
         << "\n";
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (any_found[b[i] + b[j]] != make_pair(0, 0)) {
        int p1 = any_found[b[i] + b[j]].first;
        int p2 = i;
        int p3 = j;
        int p4 = any_found[b[i] + b[j]].second;
        my_assert(p1 != p2);
        my_assert(p1 != p3);
        my_assert(p1 != p4);
        my_assert(p2 != p3);
        my_assert(p2 != p4);
        my_assert(p3 != p4);
        cout << "YES"
             << "\n";
        cout << 0 << " " << b[p3] - b[p1] << " " << b[p1] << " " << b[p2]
             << " ";
        for (int i = 0; i < n; i++) {
          if (i != p1 && i != p2 && i != p3 && i != p4) {
            cout << b[i] << " ";
          }
        }
        cout << "\n";
        if (debug) {
          vector<int> my_ans;
          my_ans.push_back(0);
          my_ans.push_back(b[p3] - b[p1]);
          my_ans.push_back(b[p1]);
          my_ans.push_back(b[p2]);
          for (int i = 0; i < n; i++) {
            if (i != p1 && i != p2 && i != p3 && i != p4) {
              my_ans.push_back(b[i]);
            }
          }
          my_assert(ok_my_ans(my_ans, {b, b + n}));
          my_assert(naive({b, b + n}));
          goto start_of_program;
        } else {
          return 0;
        }
      }
      any_found[b[i] + b[j]] = make_pair(i, j);
    }
  }
  const int nn = min(n, 25);
  vector<int> p;
  for (int i = 0; i < nn; i++) {
    p.push_back(i);
  }
  map<pair<int, int>, int> mapa;
  vector<int> ids1;
  vector<int> ids2;
  while ((clock() - start) / CLOCKS_PER_SEC < 0.8) {
    random_shuffle(p.begin(), p.end());
    int mask = 0;
    int cnt = 0;
    int sum = 0;
    bool flag = 0;
    for (auto i : p) {
      mask |= (1ll << i);
      cnt++;
      sum += b[i];
      auto it = mapa.find(make_pair(cnt, sum));
      if (it != mapa.end() && it->second != mask) {
        int mask1 = mask;
        int mask2 = it->second;
        for (int i = 0; i < nn; i++) {
          if (get_bit(mask1, i) && !get_bit(mask2, i)) {
            ids1.push_back(i);
          }
        }
        for (int i = 0; i < nn; i++) {
          if (!get_bit(mask1, i) && get_bit(mask2, i)) {
            ids2.push_back(i);
          }
        }
        flag = 1;
        break;
      }
      mapa[make_pair(cnt, sum)] = mask;
    }
    if (flag) {
      break;
    }
  }
  if ((int)(ids1.size()) > 0) {
    vector<int> ans;
    ans.push_back(0);
    for (int i = 0; i < (int)(ids1.size()); i++) {
      int id1 = ids1[i];
      int id2 = ids2[i];
      if (i % 2 == 0) {
        swap(id1, id2);
      }
      ans.push_back(b[id1] - ans.back());
      if (i != (int)(ids1.size()) - 1) {
        ans.insert(ans.begin(), b[id2] - ans.front());
      }
    }
    vector<bool> have(n, 0);
    for (auto i : ids1) {
      have[i] = 1;
    }
    for (auto i : ids2) {
      have[i] = 1;
    }
    for (int i = 0; i < n; i++) {
      if (!have[i]) {
        ans.push_back(b[i]);
      }
    }
    cout << "YES"
         << "\n";
    for (auto i : ans) {
      cout << i << " ";
    }
    cout << "\n";
    return 0;
  }
  cout << "NO"
       << "\n";
  if (debug) {
    my_assert(!naive({b, b + n}));
    goto start_of_program;
  } else {
    return 0;
  }
}
