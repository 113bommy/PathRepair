#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
double startTime;
double gct() { return ((double)clock() - startTime) / CLOCKS_PER_SEC; }
void suraj() {
  vector<int> ans;
  vector<int> input;
  int n;
  cin >> n;
  input.push_back(1);
  input.push_back(1);
  for (int i = 0; i < n - 1; i++) {
    int a;
    cin >> a;
    input.push_back(a);
  }
  int ptr = n;
  vector<int> v[n];
  for (int i = n; i >= 0; i--) {
    int a = input[i];
    if (i == ptr) {
      ans.push_back(i);
      ptr = a;
    }
  }
  sort(ans.begin(), ans.end());
  for (int i : ans) cout << i << " ";
  cout << "\n";
}
int main() {
  startTime = (double)clock();
  suraj();
  return 0;
}
