#include <bits/stdc++.h>
using namespace std;
int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false);
  int tries;
  cin >> tries;
  while (tries--) {
    int len;
    cin >> len;
    vector<int> nums(len);
    for (long long i = 0; i < (len); ++i) {
      cin >> nums[i];
    }
    int global_ma = min(1, len);
    vector<vector<int>> prefix(201);
    vector<vector<int>> count(201);
    vector<int> zahl(201);
    for (int j = 1; j <= 200; j++) {
      prefix[j].push_back(nums[0] == j);
      for (int k = 1; k < len; k++) {
        prefix[j].push_back(prefix[j].back() + (nums[k] == j));
      }
      for (int k = 0; k < len; k++) {
        if (nums[k] == j) count[j].push_back(k);
      }
    }
    for (int i = 0; i < len; i++) {
      int ele = nums[i];
      int z = zahl[ele];
      zahl[ele]++;
      if (z >= prefix[ele].back() / 2) continue;
      for (int j = 1; j < 201; j++) {
        if (j == ele) {
          global_ma = max(global_ma, prefix[ele].back());
          continue;
        }
        global_ma = max(
            global_ma,
            2 * (z + 1) +
                prefix[j][count[ele][max(0, (int)count[ele].size() - z - 1)]] -
                prefix[j][max(count[ele][z] - 1, 0)]);
      }
    }
    cout << global_ma << endl;
  }
}
