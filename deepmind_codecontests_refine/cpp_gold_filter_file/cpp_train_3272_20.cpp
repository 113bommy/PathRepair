#include <bits/stdc++.h>
using namespace std;
int main() {
  int *box, index;
  cin >> index;
  box = new int[index];
  for (int g = 0; g < index; g++) {
    cin >> box[g];
  }
  for (int i = 0; i < index - 1; i++)
    for (int j = 1 + i; j < index; j++) {
      if (box[i] > box[j]) swap(box[i], box[j]);
    }
  for (int h = 0; h < index; h++) cout << box[h] << "\t";
}
