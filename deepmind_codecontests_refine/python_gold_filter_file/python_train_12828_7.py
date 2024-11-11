from sys import stdin
T=int(stdin.readline().strip())
for caso in range(T):
    n,b,c=map(int,stdin.readline().strip().split())
    x=max(1,b+c+1-n)
    print(min(x,n),min(b+c-1,n))
