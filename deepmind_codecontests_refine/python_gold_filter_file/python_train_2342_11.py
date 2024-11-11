n=int(input())
l1=list(map(int,input().split()))
l2=l1.copy()
l2.sort()
for i in range (n):
    max1=max(l1[n-1]-l1[i],l1[i]-l1[0])
    if(i==0):
        min1=l1[1]-l1[0]
    elif(i==n-1):
        min1=l1[n-1]-l1[n-2]
    else:
        min1=min(l1[i]-l1[i-1],l1[i+1]-l1[i])
    print(min1,max1)
