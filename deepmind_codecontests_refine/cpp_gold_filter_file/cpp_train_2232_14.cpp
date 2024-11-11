#include <bits/stdc++.h>
using namespace std;
int main() {
  long int Calry1Val;
  long int Calry2Val;
  long int Calry3Val;
  long int Calry4Val;
  long int Length;
  long int SumCalry = 0;
  cin >> Calry1Val >> Calry2Val >> Calry3Val >> Calry4Val;
  char StripVal[100001];
  cin.getline(StripVal, 100001);
  cin.getline(StripVal, 100001);
  Length = strlen(StripVal);
  for (long long int i = 0; i < Length; i++) {
    if (StripVal[i] == '1') {
      SumCalry += Calry1Val;
    } else if (StripVal[i] == '2') {
      SumCalry += Calry2Val;
    } else if (StripVal[i] == '3') {
      SumCalry += Calry3Val;
    } else {
      SumCalry += Calry4Val;
    }
  }
  cout << SumCalry;
  return 0;
}
