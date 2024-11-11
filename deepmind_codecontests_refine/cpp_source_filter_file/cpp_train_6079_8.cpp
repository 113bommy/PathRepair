#include <bits/stdc++.h>
using namespace std;
int main() {
  string name;
  int n, First[100000], End[100000], Freq[100000], flag = 0;
  cin >> name;
  cin >> n;
  for (int i = 0; i < name.size() - 1; i++) {
    if (name[i] == name[i + 1]) {
      flag++;
      Freq[i] = flag;
    } else if (name[i] != name[i + 1]) {
      Freq[i] = flag;
    }
  }
  for (int i = 0; i < n; i++) {
    cin >> First[i] >> End[i];
  }
  for (int k = 0; k < n; k++) {
    cout << Freq[End[k] - 2] - Freq[First[k] - 2] << endl;
  }
  return 0;
}
