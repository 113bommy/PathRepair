n=int(input())
p=list(map(int,input().split()))
a=[49999*(i+1)for i in range(n)]
b=[49999*i for i in range(n,0,-1)]
for i in range(n):b[p[i]-1]+=i
print(*a)
print(*b)