#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
while(true){
int a,b;
cin >> a >> b;
if(a==0&&b==0)return 0;
int x[4],y[4];
for(int i=0;i<4;i++){
x[i]=a%10;
a/=10;
y[i]=b%10;
b/=10;
}

int hit=0,blow=0;
for(int i=0;i<4;i++)if(x[i]==y[i])hit++;

for(int i=0;i<4;i++){
for(int j=0;j<4;j++)if(x[i]==y[j])blow++;
}
blow-=hit;

printf("%d %d\n",hit,blow);
}
}