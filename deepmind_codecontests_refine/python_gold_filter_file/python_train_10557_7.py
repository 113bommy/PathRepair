n,k=map(int,input().split())
l=[i for i in range(1,2*n+1)]
for i in range(k):
    l[2*i],l[2*i+1]=l[2*i+1],l[2*i]
print(*l)