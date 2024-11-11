N=int(input())
D,X=map(int,input().split())
ans=0
for _ in[0]*N:
    A=int(input())
    ans+=(D+A-1)//A
print(ans+X)
