#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,X;
  cin >> N >> X;
  int m;
  int a;
  for (int i=0;i<N;i++){
    cin >> m;
    a= i==0?m:min(m:a);
    X-=m;
  }
  cout << N+X/a << endl;
}
