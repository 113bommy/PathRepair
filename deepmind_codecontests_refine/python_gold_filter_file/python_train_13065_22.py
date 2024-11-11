n,m=map(int,input().split())
c=0
for i in range(n):
    a=list(map(int,input().split()))
    for j in range(0,2*m,2):
        if a[j]==1 or a[j+1]==1:
            c+=1
print(c)            