import math
import bisect as bis
import heapq
M=1000000007
t,k=map(int,input().split())
a=[0]*100005
for i in range(k):
	a[i]=1

for i in range(k,100005):
	a[i]=(a[i-1]+a[i-k])%M

for i in range(1,100005):
	a[i]+=a[i-1]
	a[i]%=M
for x in range(t):
	a1,b1=map(int,input().split())
	print((a[b1]-a[a1-1])%M)