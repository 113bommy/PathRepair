a=list(map(int,input().split()))
m=0
for i in range(14):
    if a[i]==0:
        continue
    b=[0]*14
    for j in range(14):
        b[j]=a[j]
    z=b[i]
    b[i]=0
    for j in range(14): b[j]+=z//14
    for j in range(1,z%14+1):b[(i+j)%14]+=1
    s=0
    for j in range(14):
        if b[j]%2==0:
            s+=b[j]
    if m<s:m=s
print(m)
