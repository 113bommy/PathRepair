n,d=(int(i) for i in input().split())
l1=[int(i) for i in input().split()]
l2=[int(i) for i in input().split()]
l1[d-1]+=l2[0]
k=l1[d-1]
k1=d-1
for i in range(n):
    if(l1[i]<=k):
        l1.remove(k)
        l1.insert(i,k)
        k1=i
        break
for i in range(n):
    if(i<k1):
        l1[i]+=l2[i+1]
    if(i>k1):
        l1[i]+=l2[n+k1-i]
        if(l1[i]>k):
            k1+=1
print(k1+1)