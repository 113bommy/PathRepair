#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1000000007;
long long int N;
long long int num[100000];
long long int on[50];
long long int over[50];
long long int box[50];
list<long long int> ans;
int main() {
  ios::sync_with_stdio(false);
  box[0] = 1;
  for (int i = 1; i < 50; i++) {
    box[i] = box[i - 1] * 2;
  }
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> num[i];
    for (int j = 49; j >= 0; j--) {
      if (num[i] == box[j]) {
        on[j]++;
        break;
      }
      if (num[i] > box[j]) {
        over[j]++;
        break;
      }
    }
  }
  for (int i = 0; i < 49; i++) {
    if (on[i] < on[i + 1]) {
      over[i + 1] += on[i + 1] - on[i];
      on[i + 1] = on[i];
    }
  }
  for (long long int i = (on[0] + 1) / 2; i <= on[0]; i++) {
    long long int box_on[50] = {};
    long long int box_over[50] = {};
    long long int s_over[50] = {};
    for (int j = 0; j < 50; j++) {
      box_over[j] = over[j];
      if (on[j] > i) {
        box_on[j] = i;
        box_over[j] += on[j] - i;
      } else {
        box_on[j] = on[j];
      }
    }
    s_over[49] = box_over[49];
    bool flag = true;
    for (int j = 48; j >= 0; j--) {
      s_over[j] = s_over[j + 1] + box_over[j];
      if (s_over[j] > box_on[j]) {
        flag = false;
        break;
      }
    }
    if (flag) ans.push_back(i);
  }
  if (ans.empty()) {
    cout << "-1\n";
    return 0;
  }
  for (auto i : ans) {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}
