#include <bits/stdc++.h>
using namespace std;
bool option(int a, int b) { return a > b; }
int main() {
  int n, a, b;
  cin >> n >> a >> b;
  vector<int> memories(n);
  for (int i = 0; i < n; i++) {
    cin >> memories[i];
  }
  sort(memories.begin(), memories.end(), option);
  cout << memories[a - 1] - memories[a];
  return 0;
}
