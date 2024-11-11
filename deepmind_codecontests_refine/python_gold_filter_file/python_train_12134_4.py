n=int(input())
l=[int(j) for j in input().split()]
k=1
mx=1
for i in range(1,n):
    if l[i]>l[i-1]:
        k=k+1
        mx=max(k,mx)
    else:
        k=1
print(mx)
