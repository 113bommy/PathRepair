#include "stdio.h"
#include <vector>
#include <queue>
#include <set>

using namespace std;

int x[10];

int main()
{
while(1)
{
int n,k;
scanf("%d",&n);
scanf("%d",&k);
if(n == 0 && k == 0)
{
break;
}
for(int i = 0; i < n; i++)
{
scanf("%d",&x[i]);
}

int w = 1;
for(int i = 0; i < k; i++)
{
w *= n;
}

set<int> sw;
for(int i = 0; i < w; i++)
{
priority_queue<int> q1;
vector<int> q2;
int s = i;
for(int i = 0; i < k; i++)
{
int l = s % n;
q1.push(l);
q2.push_back(l);
s /= n;
}

int flgw = 0;
int mae = -1;
for(int ii = 0; ii < k; ii++)
{
if(mae == q1.top())
{
flgw = 1;
break;
}
mae = q1.top();
q1.pop();
}
if(flgw == 1)
{
continue;
}

int g = 0;
for(int ii = 0; ii < k; ii++)
{
if(x[q2[ii]] < 10)
{
g = g * 10 + x[q2[ii]];
}
else
{
g = g * 100 + x[q2[ii]];
}
}
sw.insert(g);
}

printf("%d\n",sw.size());
{
return 0;
}