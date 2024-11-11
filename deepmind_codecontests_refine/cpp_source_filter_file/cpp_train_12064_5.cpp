include<iostream>
#include<cstdio>
#include<math.h>
using namespace std;

int main(){
  long long s=0;
  int i,j,n;

  cin >> n;
  for(i=0;i<n;i++){
    cin >> j;
    s+=j;
  }
  cout << s/n << endl;

  return 0;


}