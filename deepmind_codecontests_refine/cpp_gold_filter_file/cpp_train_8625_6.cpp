#include<bits/stdc++.h> 
using namespace std;
char a[100007];
int main()
{
  scanf("%s",a);
  int l=strlen(a),x=0,i;
  for(i=0;i<l;i++)
    if(a[i]=='g')
	  x++;
  printf("%d\n",min(l/2,x)-min(l-l/2,l-x));
  return 0;
}