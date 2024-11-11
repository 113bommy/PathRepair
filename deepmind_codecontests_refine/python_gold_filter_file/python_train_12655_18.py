n,k=map(int,input().split())
l=list(map(int,input().split()))
b=[]
for i in range(n):
    b.append(l[i])
sumoriginal=0
for i in range(n):
    sumoriginal+=l[i]
a=[]
for i in range(n):
    if i%2==0:
        #print(l[0])
        #rint("1")
        if l[0]>=l[i]:
            a.append(l[0])
        else:
            a.append(l[i])
            l[0]=l[i]
    else:
        #print(l[0])
        #print("2")
        if k-l[0]>=l[i]:
            a.append(k-l[0])
        else:
            a.append(l[i])
            l[0]=k-l[i]
sumnew=0
for i in range(n):
    sumnew+=a[i]
if sumnew>sumoriginal:
    print(sumnew - sumoriginal)
    print(*a)
else:
    print(0)
    print(*b)
#903
#164 336 238 262 373 249 251 249 251 249    