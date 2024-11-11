N=int(input())
A=[list(map(int,input().split())) for _ in range(N)]

r=0
for i in range(N-1,-1,-1):
    a,b=A[i]
    a+=r
    r+=-(-a//b)*A[i][1]-a
print(r)