n,k=map(int,input().split())
count=0
l=[int(ele) for ele in input().split()]
for i in range(len(l)):
    if count==k:break
    if i%2!=0:
        l[i]-=1
        if l[i]>l[i-1] and l[i]>l[i+1]:
            count+=1
            continue
        else:l[i]+=1
print(*l)