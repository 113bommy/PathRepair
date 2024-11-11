c,b=map(int,input().split())
a=set(range(1,b+1))
for i in range(c):
    n,m=map(int,input().split())
    a-=set(range(n,m+1))
print(len(a))
print(*a)
