#include <bits/stdc++.h>
using namespace std;
void ask(int a, int b) {
  cout << "?" << a << " " << b << endl;
  fflush(stdout);
}
map<long long, long long> mp;
map<long long, pair<long long, long long> > mp1;
vector<int> v = {4, 8, 15, 16, 23, 42};
vector<long long> ans;
void answer() {
  cout << "!";
  for (int i = 1; i <= 6; i++) cout << " " << ans[i];
  cout << endl;
  fflush(stdout);
}
int main() {
  for (int i = 0; i < (int)v.size(); i++) {
    mp[((v[i]) * (v[i]))] = v[i];
  }
  for (int i = 0; i < (int)v.size(); i++) {
    for (int j = i + 1; j < (int)v.size(); j++) {
      long long val = v[i] * v[j];
      mp1[val] = pair<long long, long long>(v[i], v[j]);
    }
  }
  ans = vector<long long>(7);
  long long x1, x2;
  ask(1, 2);
  cin >> x1;
  ask(2, 3);
  cin >> x2;
  pair<long long, long long> temp1 = mp1[x1];
  pair<long long, long long> temp2 = mp1[x2];
  if (temp1.first == temp2.first) {
    ans[2] = temp1.first;
    ans[1] = temp1.second;
    ans[3] = temp2.second;
  } else if (temp1.first == temp2.second) {
    ans[2] = temp1.first;
    ans[1] = temp1.second;
    ans[3] = temp2.first;
  } else if (temp1.second == temp2.first) {
    ans[2] = temp1.second;
    ans[1] = temp1.first;
    ans[3] = temp2.second;
  } else if (temp1.second == temp2.second) {
    ans[2] = temp1.second;
    ans[1] = temp1.first;
    ans[3] = temp2.first;
  }
  ask(4, 5);
  cin >> x1;
  ask(5, 6);
  cin >> x2;
  temp1 = mp1[x1];
  temp2 = mp1[x2];
  if (temp1.first == temp2.first) {
    ans[5] = temp1.first;
    ans[4] = temp1.second;
    ans[6] = temp2.second;
  } else if (temp1.first == temp2.second) {
    ans[5] = temp1.first;
    ans[4] = temp1.second;
    ans[6] = temp2.first;
  } else if (temp1.second == temp2.first) {
    ans[5] = temp1.second;
    ans[4] = temp1.first;
    ans[6] = temp2.second;
  } else if (temp1.second == temp2.second) {
    ans[5] = temp1.second;
    ans[4] = temp1.first;
    ans[6] = temp2.first;
  }
  answer();
  return 0;
}
