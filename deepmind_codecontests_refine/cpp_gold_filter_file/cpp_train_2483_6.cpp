#include <iostream>
using namespace std;
int a[51];
int main(){
  int n,m;cin>>n>>m;
  for(int i = 0; m > i; i++){
  	int c,d;cin>>c>>d;
    a[c-1]++;
    a[d-1]++;
  }
  for(int i = 0; n > i; i++){
  	cout << a[i] << endl;
  }
}
  