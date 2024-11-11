n=int(input())
arr=[int(x) for x in input().split()]
max1=max(arr)
i2=arr.index(max1)+1
min1=min(arr)
i1=arr.index(min1)+1
ans=max(abs(n-i1),abs(n-i2),abs(1-i1),abs(1-i2))
print(ans)