n,k=map(int,input().split())
list1=list(map(int,input().split()))
list1.sort()
max1=0
for i in range(1,len(list1)):
    if abs(list1[i-1]-list1[i])>max1:
        max1=abs(list1[i-1]-list1[i])+0
max1=max1/2
p=list1[0]-0
q=k-list1[n-1]

ans=max(max1,p,q)
print(ans)
