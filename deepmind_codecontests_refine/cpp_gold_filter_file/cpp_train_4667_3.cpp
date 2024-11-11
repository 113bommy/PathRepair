#include<bits/stdc++.h>
using namespace std;

char fi[105][105];
int n,m;
bool ix[105];
bool iy[105];

int main()
{
cin >> n >> m;
for(int i=1;i<=n;i++)
{
getchar();
for(int j=1;j<=m;j++)
{
scanf("%c",&fi[i][j]);
if(fi[i][j] == '#')
{
ix[i] = 1;
iy[j] = 1;
}
}
}
for(int i=1;i<=n;i++)
{
if(!ix[i]) continue;
for(int j=1;j<=m;j++)
{
if(!iy[j]) continue;
printf("%c",fi[i][j]);
}
printf("\n");
}
return 0;
}
