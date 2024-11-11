#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> count_array;
  count_array.resize(101);
  fill(count_array.begin(), count_array.end(), 0);
  int size = 0;
  cin >> size;
  const int half = size / 2;
  for (int i = 0; i < size; ++i) {
    int key = 0;
    cin >> key;
    count_array[key]++;
  }
  vector<int> pair_list;
  for (int i = 0; i < count_array.size(); ++i) {
    if (count_array[i] == half) pair_list.push_back(i);
  }
  if (pair_list.size() == 2) {
    cout << "YES" << endl;
    for (auto i : pair_list) {
      cout << i << endl;
    }
  } else
    cout << "NO" << endl;
  return 0;
}
