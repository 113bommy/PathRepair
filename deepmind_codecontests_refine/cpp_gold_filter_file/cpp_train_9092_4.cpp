#include <bits/stdc++.h>
using namespace std;
int freq[10];
vector<int> v;
bool cmp(int a, int b) { return a > b; }
int main() {
  int n;
  cin >> n;
  int tmp1;
  int total = 0;
  for (int i = 0; i < n; i++) {
    cin >> tmp1;
    freq[tmp1]++;
    total += tmp1;
  }
  total %= 3;
  bool ok = false;
  if (total == 1) {
    if (freq[1] > 0) {
      freq[1]--;
    } else if (freq[4] > 0) {
      freq[4]--;
    } else if (freq[7] > 0) {
      freq[7]--;
    } else if (freq[2] > 1) {
      freq[2] -= 2;
    } else if (freq[2] > 0 && freq[5] > 0) {
      freq[2]--;
      freq[5]--;
    } else if (freq[5] > 1) {
      freq[5] -= 2;
    } else if (freq[8] > 0 && freq[5] > 0) {
      freq[8]--;
      freq[5]--;
    } else if (freq[8] > 1) {
      freq[8] -= 2;
    }
  } else if (total == 2) {
    if (freq[2] > 0) {
      freq[2]--;
    } else if (freq[5] > 0) {
      freq[5]--;
    } else if (freq[8] > 0) {
      freq[8]--;
    } else if (freq[1] > 1) {
      freq[1] -= 2;
    } else if (freq[1] > 0 && freq[4] > 0) {
      freq[1]--;
      freq[4]--;
    } else if (freq[4] > 1) {
      freq[4] -= 2;
    } else if (freq[7] > 0 && freq[1] > 0) {
      freq[7]--;
      freq[1]--;
    } else if (freq[7] > 0 && freq[4] > 0) {
      freq[7]--;
      freq[4]--;
    } else if (freq[7] > 1) {
      freq[7] -= 2;
    }
  }
  total = 0;
  for (int i = 0; i <= 9; i++) {
    for (int j = 1; j <= freq[i]; j++) {
      v.push_back(i);
      total += i;
    }
  }
  total %= 3;
  if (total != 0 || v.empty() || freq[0] == 0) {
    cout << -1;
    return 0;
  }
  sort(v.begin(), v.end(), cmp);
  if (v[0] == 0) {
    cout << 0;
    return 0;
  }
  for (int i = 0; i < v.size(); i++) {
    cout << v[i];
  }
}
