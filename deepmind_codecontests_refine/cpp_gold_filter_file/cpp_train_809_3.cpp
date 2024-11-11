#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
  scanf("%d",&n);
  int temp = 0;
  for(int i = 0;i<n;i++){
  	int t;
    cin>>t;
    temp^=t;
  }
  if(temp==0)
    puts("Yes");
  else
    puts("No");
  return 0;
}