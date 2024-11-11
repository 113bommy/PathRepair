n=int(input())
p=list(map(int,input().split()))
print(*[30000*i for i in range(1,n+1)])
b=[30000*(n-i)for i in range(n)]
for i in range(n):
    b[p[i]-1]+=i
print(*b)