N=int(input())
m=0
end=0
for _ in range(N):
    a,b=map(int,input().split())
    if a>m:
        m,end=a,b
print(m+end)