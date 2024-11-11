### B. Different Rules
for _ in range(int(input())):
    n,x,y=map(int,input().split())
    maxim=min(x+y-1, n)
    m=min(x+y-n+1, n)
    minim=max(m,1)
    print(minim, maxim)