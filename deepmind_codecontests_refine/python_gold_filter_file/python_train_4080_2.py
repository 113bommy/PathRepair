n,k=[int(i) for i in input().split()]
a=[int(i) for i in input().split()]
a.sort()
d={}
for i in range(len(a)):
    temp=a[i]
    curr=0
    while temp:
        if temp not in d or d[temp][0]<k:
            if temp in d:
                d[temp][0]+=1
                d[temp][1]+=curr
            else:
                d[temp]=[1,curr]
        curr+=1
        temp=temp>>1
ans=10000000000000000
# print(d)
for i in d:
    if d[i][0]>=k:
        ans=min(ans,d[i][1])
print(ans)