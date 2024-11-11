#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, len;
  cin >> n >> len;
  string p = "";
  string num[n];
  for (int i = 0; i < len; i++) p += (i + '0');
  bool donepermuations = 0;
  vector<string> storePerm;
  while (!donepermuations) {
    storePerm.push_back(p);
    if (!next_permutation(p.begin(), p.end())) donepermuations = 1;
  }
  for (int i = 0; i < n; i++) cin >> num[i];
  int ans = 1000000;
  for (int i = 0; i < storePerm.size(); i++) {
    string swapLikeThis = storePerm[i];
    int temp[n];
    for (int j = 0; j < n; j++) {
      string swapThis = num[j], original = num[j];
      for (int k = 0; k < len; k++) {
        if (k != (swapLikeThis[k] - '0'))
          swapThis[k] = original[swapLikeThis[k] - '0'];
      }
      temp[j] = stoi(swapThis);
    }
    int largest = *max_element(temp, temp + n);
    int smallest = *min_element(temp, temp + n);
    ans = min(ans, (largest - smallest));
  }
  cout << ans << endl;
}
