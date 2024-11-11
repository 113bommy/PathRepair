#include <bits/stdc++.h>
using namespace std;
int N, X, Y;
bool same[15];
void printSub(vector<int> sub) {
  cout << "? " << sub.size() << " ";
  for (auto x : sub) cout << x << " ";
  cout << "\n";
  cout.flush();
}
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> N >> X >> Y;
  int diff = -1;
  for (int i = 0; i <= 9; i++) {
    vector<int> sub;
    for (int j = 1; j <= N; j++)
      if (j & (1 << i)) sub.push_back(j);
    if (sub.empty()) {
      same[i] = 1;
      continue;
    }
    printSub(sub);
    int ans;
    cin >> ans;
    if (!ans or ans == X)
      same[i] = 1;
    else
      diff = i;
  }
  vector<int> bin;
  for (int j = 1; j <= N; j++)
    if (j & (1 << diff)) bin.push_back(j);
  int ini = 0;
  int fin = bin.size() - 1;
  while (ini < fin) {
    int mid = (ini + fin) / 2;
    vector<int> sub;
    for (int i = ini; i <= mid; i++) sub.push_back(bin[i]);
    printSub(sub);
    int ans;
    cin >> ans;
    if (ans == Y or ans == X ^ Y)
      fin = mid;
    else
      ini = mid + 1;
  }
  int pos1 = bin[ini];
  int pos2 = 0;
  for (int i = 0; i <= 9; i++) {
    if (same[i])
      pos2 += (pos1 & (1 << i));
    else if (!(pos1 & (1 << i)))
      pos2 += pos1 & (1 << i);
  }
  if (pos1 > pos2) swap(pos1, pos2);
  cout << "! " << pos1 << " " << pos2 << "\n";
  cout.flush();
  return 0;
}
