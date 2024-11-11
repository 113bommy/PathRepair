MOD = 1000000007
ii = lambda : int(input())
si = lambda : input()
dgl = lambda : list(map(int, input()))
f = lambda : map(int, input().split())
il = lambda : list(map(int, input().split()))
ls = lambda : list(input())
n=ii()
c=0
for i in range(1,n):
    x=i;t=1
    for j in range(n-2):
        if x==1:
            t=0
        x=(x*i)%n
    c+=t
print(c)