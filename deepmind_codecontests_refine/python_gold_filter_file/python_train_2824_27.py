n,k=map(int,input().split())
r=input().split()
c=1
m=1
for i in range(1,len(r)):
    if r[i]!=r[i-1]:
        m+=1
        if m>=c:
            c=m
    else:
        m=1
print(c)
