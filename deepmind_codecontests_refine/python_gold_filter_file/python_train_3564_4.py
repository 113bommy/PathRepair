t=int(input())
for i in range(t):
    n=int(input())
    a=[int(ele)for ele in input().split()]
    b=[int(ele)for ele in input().split()]
    hasnegative=False
    hasone=False
    for i in range(n):
        if a[i]>b[i] and not(hasnegative):
            print("NO")
            break
        if a[i]<b[i] and not(hasone):
            print("NO")
            break
        if a[i]==1:
            hasone=True
        if a[i]==-1:
            hasnegative=True
    else:
        print("YES")