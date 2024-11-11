n=int(input())
a=[int(x) for x in input().split()]
ans =0
for i in range(0, 2*n, 2):
    for j in range(i+2,2*n):
        if a[i] == a[j]:
            for k in range(j-1, i, -1):
                t=a[k]
                a[k]=a[k+1]
                a[k+1]=t
                ans+=1
            break
print(ans)