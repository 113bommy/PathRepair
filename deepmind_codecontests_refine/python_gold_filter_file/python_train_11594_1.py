s,k=[int(i) for i in input().split()]
a=[-1,0,1,1]
i=3
while a[i]<=pow(10,9):
    i+=1
    a.append(0)
    if i<=k:
        for j in range(1,i):
            a[i]+=a[j]
    else:
        for j in range(i-k,i):
            a[i]+=a[j]
b=[]
for j in range(i,0,-1):
    if a[j]<=s:
        b.append(a[j])
        s-=a[j]
        if s==0:
            b.append(0)
            break
print(len(b))
for i in b:
    print(i,end=' ')