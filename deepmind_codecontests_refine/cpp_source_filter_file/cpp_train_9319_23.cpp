#include <bits/stdc++.h>
using namespace std;
long long A[int(1e3) + 5], B[int(1e3) + 5];
vector<long long> AnsesA;
vector<long long> AnsesB;
int main() {
  int n;
  long long my_ans = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> A[i];
  for (int i = 0; i < n; ++i) cin >> B[i];
  for (int i = 0; i < n; ++i) {
    AnsesA.push_back(A[i] ^ A[i + 1]);
    AnsesB.push_back(B[i] ^ B[i + 1]);
    my_ans = max(my_ans, AnsesA[0] + AnsesB[0]);
    for (int g = i + 2; g < n; ++g) {
      AnsesA.push_back(AnsesA[g - 2 - i] ^ A[g]);
      AnsesB.push_back(AnsesB[g - 2 - i] ^ B[g]);
      my_ans = max(my_ans, AnsesA[g - 1 - i] + AnsesB[g - 1 - i]);
    }
    AnsesA.clear();
    AnsesB.clear();
  }
  cout << my_ans;
  return 0;
}
