#include <bits/stdc++.h>
using namespace std;
set<int> st;
set<int>::iterator it;
map<int, int> mp;
map<int, int>::iterator itr;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL), cout.tie(NULL);
  int a, b, s = -1;
  char arr[101][101];
  string str = "";
  cin >> a >> b;
  for (int i = 0; i < a; i++)
    for (int k = 0; k < b; k++) cin >> arr[i][k];
  for (int i = 0; i < a; i++) {
    for (int k = 0; k < b; k++) {
      for (int l = 0; l < a; l++)
        if (l != k && arr[i][l] == arr[i][k]) s++;
      for (int q = 0; q < b; q++)
        if (q != i && arr[q][k] == arr[i][k]) s++;
      if (s == -1) str += arr[i][k];
      s = -1;
    }
  }
  cout << str << endl;
  return 0;
}
