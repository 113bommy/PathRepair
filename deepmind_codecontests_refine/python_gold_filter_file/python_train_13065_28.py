(n,m)=map(int,input().split())
count=0
for i in range(n):
    l=list(map(int,input().split()))
    for i in range(0,2*m,2):
        if l[i]==1 or l[i+1]==1:
            count=count+1
print(count)
