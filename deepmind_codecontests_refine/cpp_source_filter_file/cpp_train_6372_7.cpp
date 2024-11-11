#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  string str;
  cin >> str;
  char arr[k];
  for (int i = 0; i < k; i++) {
    cin >> arr[i];
  }
  int pos[26];
  memset(pos, 0, sizeof pos);
  for (int i = 0; i < k; i++) {
    pos[arr[i] - 97] = 1;
  }
  for (int i = 0; i < str.size(); i++) {
    if (pos[str[i] - 97] != 1) str.replace(i, 1, " ");
  }
  stringstream ss(str);
  string word;
  unsigned long int l, sum = 0;
  while (ss >> word) {
    l = word.size();
    sum += l * (l + 1) / 2;
  }
  cout << sum;
  return 0;
}
