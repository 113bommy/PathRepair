def data():
    return map(int,input().split())
n,k=data()
l=list(data())
s=sum(l[0:k])
l1=[(s,0)]
for i in range(1,n-2*k+1):
    if l1[-1][0]<s-l[i-1]+l[i+k-1]:
        l1.append((s-l[i-1]+l[i+k-1],i))
    else:
        l1.append(l1[-1])
    s=s-l[i-1]+l[i+k-1]

s=sum(l[n-k:n])
l2=[(s,n-k)]
for i in range(n-k-1,k-1,-1):
    if l2[-1][0]<=s+l[i]-l[i+k]:
        l2.append((s+l[i]-l[i+k],i))
    else:
        l2.append(l2[-1])
    s=s+l[i]-l[i+k]

m=0
a=()
for i in range(0,n-2*k+1):
    if m<l1[i][0]+l2[n-2*k-i][0]:
        m=l1[i][0]+l2[n-2*k-i][0]
        a=(l1[i][1],l2[n-2*k-i][1])
print(a[0]+1,a[1]+1)