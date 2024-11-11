n=int(input())
p=list(map(int,input().split()))
a=[30000*(i+1) for i in range(n)]
r=[0]*n
f=1
for i in p:
    r[i-1]=f
    f+=1
b=[30000*(n-i-1)+r[i] for i in range(n)]
print(*a)
print(*b)
