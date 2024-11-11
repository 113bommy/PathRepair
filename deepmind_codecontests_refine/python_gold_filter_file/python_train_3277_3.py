from collections import *
s=list(input())
n=int(input())
l=list(map(int,input().split()))
d=defaultdict(int)
for i in l:
    d[i]+=1
c=0
m=len(s)
for i in range(m//2):
    c+=d[i+1]
    if(c&1):
        s[i],s[m-i-1]=s[m-i-1],s[i]
print(''.join(s))
