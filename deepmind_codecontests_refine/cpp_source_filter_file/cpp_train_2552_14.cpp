#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> max_appearance(n);
  for (int i = 0; i < n; i++) cin >> max_appearance[i];
  sort(max_appearance.begin(), max_appearance.end());
  int current = max_appearance[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    if (current == max_appearance[i])
      max_appearance[i]--;
    else if (current < max_appearance[i])
      max_appearance[i] = current - 1;
    current = max_appearance[i];
  }
  int count = 0;
  for (int i = 0; i < n; i++)
    count += max_appearance[i] > 0 ? max_appearance[i] : 0;
  cout << count;
  return 0;
}
