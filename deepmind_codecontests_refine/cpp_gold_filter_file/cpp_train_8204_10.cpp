#include<bits/stdc++.h>
using namespace std; 
int main(){
  int l,i,j,b[256]={0},n,r=0;
  char s[256];
  scanf("%d%s",&l,s);
  for(i=1;i<l-1;i++)
  {
    for(j='a';j<='z';j++)
	{
		b[j]=0;
	}
    for(j=0;j<i;j++)
	{
		b[s[j]]=1;
	}
    n=0;
    for(j=i;j<l;j++)
	{
		if(b[s[j]])
		{
			b[s[j]]=0;
			n++;
		}
	}
    r=max(r,n);
  }
  printf("%d\n",r);
  return 0;
}