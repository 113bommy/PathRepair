# include <bits/stdc++.h>
using namespace std;

int main(){
  int N, X;
  cin >> N >> X;
  int s=0;
  int a=1000;
  for (int i=0; i<N; i++){
    int m;
    cin >> m;
    s+=m;
    a=min(m,a);
  }
  cout << N+(X-s)/a << endl;
}

