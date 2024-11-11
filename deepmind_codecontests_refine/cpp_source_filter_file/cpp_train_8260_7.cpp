#include <bits/stdc++.h>
using namespace std;
int n;
unordered_set<int> conjunto[2];
int act = 1, ant = 0;
int arr[100002];
bool existe[1000002];
int main() {
  ios_base::sync_with_stdio(0);
  ;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> arr[i];
  for (int i = 1; i <= n; i++) {
    swap(ant, act);
    conjunto[act].clear();
    for (int it : conjunto[ant]) {
      conjunto[act].insert(it | arr[i]);
      existe[it | arr[i]] = true;
    }
    conjunto[act].insert(arr[i]);
    existe[arr[i]] = true;
  }
  int resp = 0;
  for (int i = 0; i <= (1 << 20) - 1; i++)
    if (existe[i]) resp++;
  cout << resp << "\n";
  return 0;
}
