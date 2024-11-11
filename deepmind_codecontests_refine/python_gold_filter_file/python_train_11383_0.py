mod = 1000000007
ii = lambda : int(input())
si = lambda : input()
dgl = lambda : list(map(int, input()))
f = lambda : map(int, input().split())
il = lambda : list(map(int, input().split()))
ls = lambda : list(input())
n=ii()
l=il()
i=0
while 2**i<=n-1:
    i+=1
i-=1
sm=0
for j in range(n-1):
    if j+2**i>n-1:
        i-=1
    sm+=l[j]
    l[j+2**i]+=l[j]
    print(sm)
if n==1:
    print(0)