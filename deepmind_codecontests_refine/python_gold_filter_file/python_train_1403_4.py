n,k=map(int,input().split())
b=list(map(int,input().split()))
a=[]
tot=0
for i in range(n):
    a.append([b[i],i+1])
    tot+=a[i][0]
a.sort()
pos=0
if tot<=k:
    pos=n
else:
    for i in range(n):
        if k>=a[i][0]:
            k-=a[i][0]
        else:
            pos=i
            break
print(pos)
for i in range(pos):
    print(a[i][1],end=" ")