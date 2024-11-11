n=int(input())
d={}
arr=input().split()
for i in range(n):
    arr[i]=int(arr[i])
    d[arr[i]]=i

arr2=input().split()
ans=0
shifts=[0 for i in range(n)]
for i in range(n):
    arr2[i]=int(arr2[i])
    shift=i-d[arr2[i]]
    shifts[shift]+=1
    ans=max(ans,shifts[shift])

print(ans)
