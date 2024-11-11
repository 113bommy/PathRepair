#include <bits/stdc++.h>
using namespace std;
int n;
bool isP[100001];
vector<pair<int, int> > ans;
bool used[100001];
vector<int> unpaired;
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++) used[i] = 0;
  isP[1] = 0;
  for (int i = 2; i <= 100000; i++) isP[i] = 1;
  for (int i = 2; i <= 100000; i++) {
    if (isP[i] && (long long)i * i <= n) {
      for (int j = i * i; j <= n; j += i) {
        isP[j] = 0;
      }
    }
  }
  for (int i = 3; i <= n; i++) {
    if (isP[i]) {
      if (i * 2 <= n) {
        vector<int> nums;
        for (int j = i; j <= n; j += i) {
          if (!used[j]) nums.push_back(j);
        }
        if (nums.size() & 1) {
          ans.push_back(make_pair(nums[0], nums[2]));
          used[nums[0]] = 1;
          used[nums[2]] = 1;
          for (int j = 4; j < nums.size(); j += 2) {
            ans.push_back(make_pair(nums[j - 1], nums[j]));
            used[nums[j]] = 1;
            used[nums[j - 1]] = 1;
          }
        } else {
          for (int j = 1; j < nums.size(); j += 2) {
            ans.push_back(make_pair(nums[j - 1], nums[j]));
            used[nums[j]] = 1;
            used[nums[j - 1]] = 1;
          }
        }
      }
    }
  }
  for (int i = 2; i <= n; i += 2) {
    if (!used[i]) unpaired.push_back(i);
  }
  for (int i = 1; i < unpaired.size(); i += 2) {
    ans.push_back(make_pair(unpaired[i - 1], unpaired[i]));
  }
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i].first << " " << ans[i].second << "\n";
  }
  return 0;
}
