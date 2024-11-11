include<iostream>
#include<cstdio>
using namespace std;

int main(){

  double x,y;
  int n;

  while(scanf("%d,%lf,%lf",&n,&x,&y) != EOF){

    if(x/(y*y) >= 25) cout << n << endl;

  }

}