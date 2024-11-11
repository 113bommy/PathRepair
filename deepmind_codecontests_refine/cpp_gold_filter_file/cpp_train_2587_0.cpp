#include<iostream>
using namespace std; 
int main (){
int s,k;
scanf("%d%d",&k,&s);
int c=0,z;
for(int y=0;y<=k;y++){

for(int x=0;x<=k;x++)
{

z=s-(y+x);
if (z>=0&&z<=k)
c++;
}
}
printf("%d",c);
}