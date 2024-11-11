#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,a=99;
  cin >> N;
  for(int i=1, i<N; i++){
    int e=100000,f=0;
    for(; e!=1; e=e/10){
      f+=i%e/(e/10)+(N-i)%e/(e/10);
    }
    a=min(a,f);
  }
  cout << a << endl;
}