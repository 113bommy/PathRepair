import math
l=input().split()
n=int(l[0])
m=int(l[1])
k=int(l[2])
l=[]
i=1
a1=input().split()
ai=[int(i) for i in a1]
b1=input().split()
bi=[int(i) for i in b1]
while(i*i<=k):
    if(k%i==0 and i!=k//i):
        l.append((i,k//i))
        l.append((k//i,i))
    elif(k%i==0):
        l.append((i,i))
    i+=1

arr1=[0 for i in range(n)]
arr2=[0 for i in range(m)]
count1=0
for i in ai:
    if(i==1):
        count1+=1
    else:
        for j in range(count1):
            arr1[j]+=count1-j
        count1=0

for i in range(count1):
    arr1[i]+=count1-i
count1=0
for i in bi:
    if(i==1):
        count1+=1
    else:
        for j in range(count1):
            arr2[j]+=count1-j
        count1=0
for i in range(count1):
    arr2[i]+=count1-i
ans=0

for i in l:
    if(i[0]>n or i[1]>m):
        ans=ans
    else:
        ans+=(arr1[i[0]-1]*arr2[i[1]-1])

print(ans)
