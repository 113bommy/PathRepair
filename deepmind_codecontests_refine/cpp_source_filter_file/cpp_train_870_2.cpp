#include <bits/stdc++.h>
using namespace std;
int main() {
  int wiresnumber;
  cin >> wiresnumber;
  vector<int>* wires = new vector<int>[wiresnumber];
  for (int i = 0; i < wiresnumber; i++) {
    int size;
    cin >> size;
    for (int k = 0; k < size; k++) {
      wires[i].push_back(1);
    }
  }
  int shoots;
  cin >> shoots;
  for (int i = 0; i < shoots; i++) {
    int w, b;
    cin >> w >> b;
    int size = wires[w - 1].size();
    for (int l = 0; l < b - 1; l++) {
      if (w > 1) wires[w - 2].push_back(1);
    }
    for (int i = b; i < size; i++) {
      if (w < wiresnumber - 1) wires[w].push_back(1);
    }
    wires[w - 1].clear();
  }
  for (int i = 0; i < wiresnumber; i++) {
    cout << wires[i].size() << endl;
  }
  delete[] wires;
  return 0;
}
