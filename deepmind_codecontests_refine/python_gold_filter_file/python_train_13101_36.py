n,c,k=map(int,input().split())
t=sorted([int(input()) for i in range(n)])
ans=0
j=0
e=0
for i in t:
    if j==0:
        j=1
        e=i+k
        ans+=1
    elif e<i:
        j=1
        e=i+k
        ans+=1
    else:
        j+=1
    if j==c:
        j=0
print(ans)
