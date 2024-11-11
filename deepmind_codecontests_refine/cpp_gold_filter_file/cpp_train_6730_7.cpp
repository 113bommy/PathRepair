#include <bits/stdc++.h>
using namespace std;
map<long long, long long> dic;
long long mi = INT32_MAX;
void three() {
  long long vd = min(dic[mi], dic[mi + 2]);
  long long ro = dic[mi + 1] / 2;
  vector<long long> ans;
  int z = 0;
  if (ro <= vd) {
    for (int i = 0; i < vd; i++) {
      ans.push_back(mi + 1);
      ans.push_back(mi + 1);
    }
    for (int i = mi; i <= mi + 2; i++) {
      if (i == mi || i == mi + 2) {
        for (int j = 0; j < dic[i] - vd; j++) {
          ans.push_back(i);
          z++;
        }
      } else {
        for (int j = 0; j < dic[i]; j++) {
          ans.push_back(i);
          z++;
        }
      }
    }
  } else {
    for (int i = mi; i <= mi + 2; i++) {
      if (i == mi + 1) {
        if (dic[mi + 1] % 2 != 0) {
          ans.push_back(i);
          z++;
        }
      } else {
        for (int j = 0; j < dic[i] + ro; j++) {
          ans.push_back(i);
        }
        z += dic[i];
      }
    }
  }
  cout << z << endl;
  for (auto x : ans) {
    printf("%lld ", x);
  }
}
int main() {
  long long n;
  cin >> n;
  long long a;
  for (int i = 0; i < n; i++) {
    scanf("%lld", &a);
    dic[a]++;
    mi = min(mi, a);
  }
  if (dic[mi + 2] != 0) {
    three();
  } else {
    cout << n << endl;
    vector<long long> ans;
    for (int i = mi; i <= mi + 2; i++) {
      for (int j = 0; j < dic[i]; j++) {
        ans.push_back(i);
      }
    }
    for (auto x : ans) {
      cout << x << " ";
    }
  }
}
