include<iostream>
#include<algorithm>
using namespace std;

int main(){
  int dt[10];
  for(int i=0;i<10;i++)cin>>dt[i];
  sort(dt,dt+10);
  for(int i=9;i>=7;i--)cout<<dt[i]<<endl;
  return 0;
}