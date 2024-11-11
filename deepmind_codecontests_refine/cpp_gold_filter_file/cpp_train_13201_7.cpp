#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,A,B;
  cin >> N >> A >> B;
  vector<int> P(N);
  int a = 0, b = 0, c = 0;
  for (int i = 0; i < N; i++){
    cin >> P[i];
    if (P[i] <= A){
      a++;
    } else if (P[i] >= B + 1){
      c++;
    } else {
      b++;
    }
  }
  cout << min(a,min(b,c));
}