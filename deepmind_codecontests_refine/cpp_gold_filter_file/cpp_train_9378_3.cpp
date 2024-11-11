#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, temp;
  cin >> n;
  vector<int> A;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    A.push_back(temp);
  }
  unordered_map<int, int> unique;
  unordered_map<int, bool> done;
  for (int i = n - 1; i >= 0; i--) {
    if (unique.find(A[i]) == unique.end())
      unique.insert({A[i], 1});
    else
      unique[A[i]]++;
  }
  long long ans = 0;
  for (int i = 0; i < n - 1; i++) {
    unique[A[i]]--;
    if (unique[A[i]] == 0) {
      unique.erase(A[i]);
    }
    if (done.find(A[i]) == done.end()) {
      ans += unique.size();
      done.insert({A[i], true});
    }
  }
  cout << ans << endl;
  return 0;
}
