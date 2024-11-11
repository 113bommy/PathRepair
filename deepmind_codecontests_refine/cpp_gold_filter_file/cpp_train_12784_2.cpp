#include<iostream>
using namespace std;
int main(){
  int N, X;
  cin >> N >> X;
  int D = 0, cnt=1, L=0;
  for(int i=0; i<N; i++){
    cin >> L;
    if(D+L <= X) cnt++;
    D = D+L;
  }
  cout << cnt << endl;
  return 0;
}