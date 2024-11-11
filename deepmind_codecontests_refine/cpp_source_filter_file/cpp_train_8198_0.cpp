#include <bits/stdc++.h>
using namespace std;
int n, s, s2, mn = 1e9;
vector<int> Array, Copy;
map<int, int> Pos1, Pos2, Pos3, Pos4;
int main() {
  cin >> n;
  n *= 2;
  for (int x, i = 1; i <= n; i++) {
    scanf("%d", &x);
    Array.push_back(x);
    if (Pos1[x] == 0) Pos2[x] = i;
    Pos1[x] = i;
  }
  Copy = Array;
  Pos3 = Pos1;
  Pos4 = Pos2;
  for (int i = 0; i < n - 1; i += 2) {
    if (Array[i] != Array[i + 1]) {
      int j = Pos1[Array[i]] - 1;
      while (Array[i + 1] != Array[i] && j > i) {
        if (j > Pos1[Array[j - 1]])
          Pos1[Array[j - 1]]++;
        else
          Pos2[Array[j - 1]]++;
        swap(Array[j], Array[j - 1]);
        j--;
        s++;
      }
    }
  }
  for (int i = n - 1; i > 0; i -= 2) {
    if (Copy[i] != Copy[i - 1]) {
      int j = Pos4[Copy[i]] - 1;
      while (Copy[i - 1] != Copy[i] && j < i) {
        if (j < Pos4[Copy[j + 1]])
          Pos4[Copy[j + 1]]--;
        else
          Pos3[Copy[j + 1]]--;
        swap(Copy[j], Copy[j + 1]);
        j++;
        s2++;
      }
    }
  }
  cout << min(s, s2) << endl;
}
