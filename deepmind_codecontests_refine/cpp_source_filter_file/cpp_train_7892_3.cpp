#include <bits/stdc++.h>
using namespace std;
int main(){
  int A,B,C,K;
  cin >> A >> B >> C >> K;
  cout << A + B + C + max(A, B, C) * ((1 << K) - 1) << endl;
}