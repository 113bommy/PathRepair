#include <bits/stdc++.h>
using namespace std;
int *a;
int *b;
void swap(int i, int j) {
  int t = b[i];
  b[i] = b[j];
  b[j] = t;
}
map<int, int> m;
vector<int> v;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, sum = 0;
  cin >> n;
  string s;
  cin >> s;
  for (int i = 0; i < n; i++)
    if (s[i] == 'B') sum += pow(2, i);
  cout << sum;
  return 0;
}
