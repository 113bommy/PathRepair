N=int(input())
arr=list(map(int,input().split()))
brr=sorted(arr,reverse=True)
c=[]
for i in range(len(arr)):
    c.append(brr.index(arr[i])+1)
print(*c)