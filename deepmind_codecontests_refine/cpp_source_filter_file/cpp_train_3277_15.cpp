#include <bits/stdc++.h>
using namespace std;
int indexs[100000];
int main() {
  cin.sync_with_stdio(false);
  string s;
  cin >> s;
  int num;
  cin >> num;
  for (int i = 0; i < num; i++) {
    cin >> indexs[i];
    indexs[i]--;
  }
  sort(indexs, indexs + num);
  int j = 0;
  for (int i = 0; i < s.size(); i++) {
    while (j < num && indexs[j] <= i) {
      j++;
    }
    if (j % 2) {
      swap(s[i], s[s.size() - 1 - i]);
    }
  }
  cout << s << endl;
}
