#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,A,B;
  cin >> N >> A >> B;
  cout << min(A,B) << ' ' << max(A+B-N,0);
}