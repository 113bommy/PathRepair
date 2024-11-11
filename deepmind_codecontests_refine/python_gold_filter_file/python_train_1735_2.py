import math
import collections
def power(x):
    cnt=0
    while(x%3==0):
        cnt+=1
        x//=3
    return cnt

n=int(input())
l=[[0,int(x)] for x in input().split()]

for i in range(n):
    l[i][0]=-power(l[i][1])

l.sort()
for i in range(n):
    print(l[i][1],end=" ")
print()
