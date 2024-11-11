#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, K, X, Y;
  cin >> N >> K >> X >> Y;
  cout << min(N,K)*X +(N>K)*(N-K)*Y << endl;
}