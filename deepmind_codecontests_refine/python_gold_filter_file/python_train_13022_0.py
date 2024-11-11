n,m=map(int,input().split())
a=[i for i in range(1, m+1)]
for i in range(n):
    l,r=map(int,input().split())
    for i in range(l,r+1):
        if i in a:
            a.remove(i)
print(len(a))
for i in a:
    print(i,end=" ")
