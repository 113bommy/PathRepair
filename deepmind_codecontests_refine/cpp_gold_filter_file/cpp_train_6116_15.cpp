#include <bits/stdc++.h>
using namespace std;
bool bin_search(vector<int> vec, int key) {
  int l = 0;
  int r = vec.size() - 1;
  int mid;
  while (l <= r) {
    mid = (l + r) / 2;
    int val = vec[mid];
    if (val == key) {
      return true;
    }
    if (key > val) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  return false;
}
int main() {
  int seq_len, fp_len;
  cin >> seq_len >> fp_len;
  vector<int> seq;
  vector<int> fp;
  string str;
  int x;
  for (int i = 0; i < seq_len; i++) {
    cin >> x;
    seq.push_back(x);
  }
  for (int j = 0; j < fp_len; j++) {
    cin >> x;
    fp.push_back(x);
  }
  sort(fp.begin(), fp.end());
  for (int n : seq) {
    if (bin_search(fp, n)) {
      str += to_string(n) + " ";
    }
  }
  cout << str.substr(0, str.length() - 1);
}
