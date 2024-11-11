#include <bits/stdc++.h>
using namespace std;
class Swap {
 public:
  int temp;
  void swap(int &num1, int &num2);
};
void Swap::swap(int &num1, int &num2) {
  int temp;
  temp = num1;
  num1 = num2;
  num2 = temp;
}
int main() {
  int aninum;
  int i = 0, j = 0;
  int aniheight[100];
  cin >> aninum;
  for (i = 0; i < aninum; i++) {
    cin >> aniheight[i];
  }
  for (i = 0; i < aninum - 1; i++) {
    for (j = i; j < aninum - 1; j++)
      if (aniheight[j] > aniheight[j + 1]) {
        swap(aniheight[j], aniheight[j + 1]);
        cout << j + 1 << " " << j + 2 << endl;
      }
  }
}
