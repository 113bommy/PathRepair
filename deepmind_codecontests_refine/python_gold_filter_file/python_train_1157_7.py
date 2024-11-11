n=int(input())
ar=list(map(int,input().split()))
mn=float('inf')
for x in range(n):
    cur=0
    for y in range(0,n):
        cur+=ar[y]*(abs(x-y)*4+abs(x)*4)
    #print(x,cur)
    mn=min(cur,mn)
print(mn)