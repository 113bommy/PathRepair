n=int(input())
l=list(map(int,input().split()))[:n]
p=0
c=0
for i in range(len(l)):
    if p==0 and l[i]==-1:
        c+=1
    elif p>0 and l[i]==-1:
        p-=1
    else:
        p+=l[i]
print(c)