#include<bits/stdc++.h>
using namespace std;

int main(){
	int w,a,b;cin>>w>>a>>b;
  if(a>b)swap(a,b);
  cout <<max(b-a-w,0)<<endl;
}