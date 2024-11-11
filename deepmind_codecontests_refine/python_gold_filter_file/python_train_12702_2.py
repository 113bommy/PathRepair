n=int(input())
A=list(map(int,input().split()))
r=set()
def f(s,k):
    if k>=0:
        global r
        r.add(s)
        f(s+A[k-1],k-1)
        f(s,k-1)
f(0,n)
input()
for e in map(int,input().split()):print(['no','yes'][e in r])
