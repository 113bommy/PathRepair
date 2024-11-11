n=int(input())
l=list(map(int,input().split()))
i,j=0,0

for a in range(1,n):
    if l[a] < l[a-1]:
        i = a-1
        for k in range(a,n):
            if(l[i]>l[k]):
                j=k
        break
count=0
# print(l)
# print(i,j)
# print(list(reversed(l[i:j+1])))
l=l[:i]+list(reversed(l[i:j+1]))+l[j+1:]
#print(l)
for a in range(n-1):
    # print(a,a+1)
    if l[a]<l[a+1]:
        count+=1
if count==n-1:
    print("yes")
    print(i+1,j+1)
else:
    print("no")