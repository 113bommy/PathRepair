#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
 int t;
int arr[101];
scanf("%d",&t);
for(int i=0;i<t;i++)
{
 scanf("%d",&arr[i]);
}
sort(arr);
printf("%d\n",arr[t-1]-arr[0]);
}