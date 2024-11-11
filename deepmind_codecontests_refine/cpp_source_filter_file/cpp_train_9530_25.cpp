#include <bits/stdc++.h>
using namespace std;
struct Contestant {
  Contestant() : pRating(0), nRating(0) {}
  string Name;
  int pRating, nRating;
};
bool Verdict(Contestant*, int);
void Solution(void);
int main(void) {
  Solution();
  return 0;
}
void Solution(void) {
  Contestant* Array = NULL;
  int Size = 0;
  cin >> Size;
  Array = new Contestant[Size];
  for (int X = 0; X < Size; ++X) {
    cin >> (Array + X)->Name >> (Array + X)->pRating >> (Array + X)->nRating;
  }
  if (Verdict(Array, Size))
    cout << "YES";
  else
    cout << "NO";
  cout << endl;
}
bool Verdict(Contestant* Arr, int Size) {
  bool Better = false;
  for (int X = 0; X < Size && !Better; ++X) {
    if ((Arr + X)->pRating > 2400 &&
        abs((Arr + X)->nRating - (Arr + X)->pRating) > 0)
      Better = true;
  }
  return Better;
}
