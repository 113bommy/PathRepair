#include <bits/stdc++.h>
using namespace std;
int main() {
  int students;
  int puzzles;
  int f;
  cin >> students;
  cin >> puzzles;
  int sizes[puzzles];
  int difference = 1000;
  for (int i = 0; i < puzzles; i++) {
    cin >> f;
    sizes[i] = f;
  }
  vector<int> puzzlesizes(sizes, sizes + puzzles);
  sort(puzzlesizes.begin(), puzzlesizes.end());
  for (int i = 0; i < puzzles - students; i++) {
    if (puzzlesizes[i + students - 1] - puzzlesizes[i] < difference) {
      difference = puzzlesizes[i + students - 1] - puzzlesizes[i];
    }
  }
  cout << difference << endl;
}
