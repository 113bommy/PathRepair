#include <bits/stdc++.h>
using namespace std;
void dispv2(vector<vector<long> > A) {
  for (long i = 0; i < A.size() / 3; i++) {
    cout << A[i][0] << " " << A[i][1] << " " << A[i][2] << ",";
  }
  cout << "\n";
}
void dispv(vector<long> A) {
  for (auto i : A) {
    cout << i << ",";
  }
  cout << "\n";
}
void dispum(unordered_map<char, long> Q) {
  for (auto i : Q) {
    cout << i.first << " " << i.second << ",";
  }
  cout << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  unordered_map<char, long> A;
  string a, b;
  getline(cin, a);
  getline(cin, b);
  for (long i = 0; i < a.size(); i++) {
    if (a[i] != ' ') A[a[i]]++;
  }
  for (long i = 0; i < b.size(); i++) {
    if (a[i] != ' ') A[b[i]]--;
  }
  bool f = true;
  for (auto i : A) {
    if (i.second < 0) {
      f = false;
      cout << "NO";
      break;
    }
  }
  if (f) cout << "YES";
  return 0;
}
