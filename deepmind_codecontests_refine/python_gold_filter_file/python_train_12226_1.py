from sys  import stdin,stdout
from collections  import *
from math import ceil, floor , log, gcd
st=lambda:list(stdin.readline().strip())
li=lambda:list(map(int,stdin.readline().split()))
mp=lambda:map(int,stdin.readline().split())
inp=lambda:int(stdin.readline())
pr=lambda n: stdout.write(str(n)+"\n")
 
mod=1000000007
INF=float('inf')

def solve():
    n,k=mp()
    x= (n*(n-1)) >>1
    if n*k>x:
        pr(-1)
        return
    ans=[]
    for i in range(1,n+1):
        for j in range(i+1,i+k+1):
            if j==n:
                ans.append((i,n))
            else:
                ans.append((i,j%n))
    print(len(ans))
    for i in ans:
        print(*i)
    
    

for _ in range(1):
    solve()
