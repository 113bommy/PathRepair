n,k=map(int,input().split())
arr=[int(i) for i in input().split()]
brr=[int(i) for i in arr]
arr.sort()
c=0
while(c<=n and k-sum(arr[:c])>=0):
    c=c+1
print(len(arr[:c-1]))
x=0
for i in range(n):
    if brr[i] not in arr[:c-1]:
        brr[i]=-1
    else:
        print(brr.index(brr[i])+1,end=" ")
        brr[i] = -1
        x=x+1
    if x==len(arr[:c-1]):
        break

