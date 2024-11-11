#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
mt19937 rng(time(nullptr));
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int k, a, h;
  cin >> k >> a >> h;
  vector<int> PowA(17);
  PowA[0] = 1;
  auto add = [&](int a, int b) -> int {
    a += b;
    if (a >= mod) a -= mod;
    return a;
  };
  auto sub = [&](int a, int b) -> int {
    a -= b;
    if (a < 0) a += mod;
    return a;
  };
  auto mul = [&](int a, int b) -> int { return 1LL * a * b % mod; };
  for (int i = 1; i <= 16; i++) {
    PowA[i] = mul(PowA[i - 1], a);
  }
  if (k == 1) {
    if (add(mul(1, PowA[1]), mul(2, PowA[2])) == h) {
      cout << 1 << " " << 2 << "\n";
      return 0;
    }
    if (add(mul(2, PowA[1]), mul(2, PowA[1])) == h) {
      cout << 2 << " " << 1 << "\n";
      return 0;
    }
  } else {
    map<int, int> Left_Max, Right_Second;
    map<int, int> Left_Second, Right_Max;
    vector<int> place((1 << k) + 1);
    {
      int tot = 1 << (k - 1);
      for (int mask = 0; mask < 1 << (tot - 1); mask++) {
        vector<int> remain(tot);
        iota(remain.begin(), remain.end(), 1);
        vector<int> order;
        int j = 0;
        while ((int)remain.size() > 1) {
          vector<int> new_remain;
          for (int i = 0; i < (int)remain.size(); i += 2) {
            if ((1 << j) & mask) {
              new_remain.push_back(remain[i]);
              order.push_back(remain[i + 1]);
            } else {
              new_remain.push_back(remain[i + 1]);
              order.push_back(remain[i]);
            }
            j++;
          }
          remain = new_remain;
        }
        order.push_back(remain.back());
        reverse(order.begin(), order.end());
        int hash_val = 0;
        j = 1;
        for (int i = 1; i <= k - 1; i++) {
          for (int x = 0; x < (1 << (i - 1)); x++) {
            hash_val = add(hash_val, mul(order[j++], PowA[(1 << i) + 1]));
          }
        }
        Left_Max[add(hash_val, mul(order[0], PowA[1]))] = mask;
        Left_Second[add(hash_val, mul(order[0], PowA[2]))] = mask;
      }
    }
    {
      int tot = 1 << (k - 1);
      for (int mask = 0; mask < 1 << (tot - 1); mask++) {
        vector<int> remain(tot);
        iota(remain.begin(), remain.end(), (1 << (k - 1)) + 1);
        vector<int> order;
        int j = 0;
        while ((int)remain.size() > 1) {
          vector<int> new_remain;
          for (int i = 0; i < (int)remain.size(); i += 2) {
            if ((1 << j) & mask) {
              new_remain.push_back(remain[i]);
              order.push_back(remain[i + 1]);
            } else {
              new_remain.push_back(remain[i + 1]);
              order.push_back(remain[i]);
            }
            j++;
          }
          remain = new_remain;
        }
        order.push_back(remain.back());
        reverse(order.begin(), order.end());
        int hash_val = 0;
        j = 1;
        for (int i = 1; i <= k - 1; i++) {
          for (int x = 0; x < (1 << (i - 1)); x++) {
            hash_val = add(hash_val, mul(order[j++], PowA[(1 << i) + 1]));
          }
        }
        Right_Max[add(hash_val, mul(order[0], PowA[1]))] = mask;
        Right_Second[add(hash_val, mul(order[0], PowA[2]))] = mask;
      }
    }
    auto process = [&](int mask, vector<int> &remain, bool hasWinner) -> void {
      vector<int> order;
      int j = 0;
      while ((int)remain.size() > 1) {
        vector<int> new_remain;
        for (int i = 0; i < (int)remain.size(); i += 2) {
          if ((1 << j) & mask) {
            new_remain.push_back(remain[i]);
            order.push_back(remain[i + 1]);
          } else {
            new_remain.push_back(remain[i + 1]);
            order.push_back(remain[i]);
          }
          j++;
        }
        remain = new_remain;
      }
      order.push_back(remain.back());
      reverse(order.begin(), order.end());
      place[order[0]] = hasWinner ? 1 : 2;
      j = 1;
      for (int i = 1; i <= k - 1; i++) {
        for (int x = 0; x < (1 << (i - 1)); x++) {
          place[order[j++]] = (1 << i) + 1;
        }
      }
    };
    for (auto it = Left_Max.begin(); it != Left_Max.end(); it++) {
      int hash_right = sub(h, it->first);
      if (Right_Second.count(hash_right)) {
        int left_mask = it->second;
        int right_mask = Right_Second[hash_right];
        vector<int> L(1 << (k - 1));
        iota(L.begin(), L.end(), 1);
        vector<int> R(1 << (k - 1));
        iota(R.begin(), R.end(), (1 << (k - 1)) + 1);
        process(left_mask, L, true);
        process(right_mask, R, false);
        for (int i = 1; i <= (1 << k); i++) {
          cout << place[i] << " ";
        }
        return 0;
      }
    }
    for (auto it = Right_Max.begin(); it != Right_Max.end(); it++) {
      int hash_left = sub(h, it->first);
      if (Left_Second.count(hash_left)) {
        int right_mask = it->second;
        int left_mask = Left_Second[hash_left];
        vector<int> L(1 << (k - 1));
        iota(L.begin(), L.end(), 1);
        vector<int> R(1 << (k - 1));
        iota(R.begin(), R.end(), (1 << (k - 1)) + 1);
        process(left_mask, L, false);
        process(right_mask, R, true);
        for (int i = 1; i <= (1 << k); i++) {
          cout << place[i] << " ";
        }
        return 0;
      }
    }
  }
  cout << -1;
  return 0;
}
