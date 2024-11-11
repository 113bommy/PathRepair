#include<bits/stdc++.h>
using namespace std;

int main(){
  int x; cin >>x;
  for(int i=-54; i<120; i++)
  {
    for(int j=-54; j<120; j++)
    if(i*i*i*i*i-j*j*j*j*j==x){cout <<i<<" "<<j; return 0;}
  }
}