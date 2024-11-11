#include <bits/stdc++.h>
using namespace std;
int N;
int least[200001];
int main() {
  cin >> N;
  int answer[N];
  for (int x = 1; x <= N; x++) {
    int l = 0;
    cin >> l;
    least[l] = x;
  }
  int r = 0;
  int f = 0;
  for (int i = 0; i < N; i++) {
    int cont = 0;
    int z;
    cin >> z;
    cont = least[z] - r;
    if (cont > 0) {
      r = least[z];
    } else {
      cont = 0;
    }
    answer[i] = cont;
  }
  for (int g = 0; g < N; g++) {
    cout << answer[g] << " ";
  }
  return 0;
}
