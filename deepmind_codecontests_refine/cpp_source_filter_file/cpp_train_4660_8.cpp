#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000010;
int arr[MAXN];
bool visited[MAXN];
void Cycle(int i) {
  visited[i] = true;
  if (visited[i] == false) Cycle(arr[i]);
}
int main() {
  int n, Petr, Umnik, NumOfCycles = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int br = 0;
  for (int i = 0; i < n; i++) {
    if (visited[i] == false) {
      Cycle(i);
      br++;
    }
  }
  if (n % 2 == br % 2)
    cout << "Petr" << endl;
  else
    cout << "Um_nik" << endl;
  return 0;
}
