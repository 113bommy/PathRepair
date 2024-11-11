#include <bits/stdc++.h>
using namespace std;
void Find_Min_Tape_length(vector<int> &input_array, int n, int m, int k) {
  if (k == n) {
    cout << n << endl;
  } else if (k == 1) {
    cout << input_array[n - 1] - input_array[0] + 1 << endl;
  } else {
    vector<pair<int, int>> diff_array;
    for (int i = 1; i < n; i++) {
      diff_array.push_back(make_pair(input_array[i] - input_array[i - 1], i));
    }
    sort(diff_array.begin(), diff_array.end());
    int min_ans = input_array[n - 1] - input_array[0] + 1;
    for (int i = 2; i <= k; i++) {
      int max_diff_value = (diff_array.back()).first;
      int max_diff_index = (diff_array.back()).second;
      diff_array.pop_back();
      min_ans = min_ans - max_diff_value + 1;
    }
    cout << min_ans << endl;
  }
  return;
}
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> input_array;
  for (int i = 0; i < n; i++) {
    int input;
    cin >> input;
    input_array.push_back(input);
  }
  Find_Min_Tape_length(input_array, n, m, k);
  return 0;
}
