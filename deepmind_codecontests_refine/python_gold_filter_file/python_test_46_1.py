def max1(a):
    maxi=0
    for i in range(len(a)):
        if a[i]>=a[maxi]:
            maxi=i
    return maxi

for i in range(int(input())):
    n=int(input())
    a=[int(j) for j in input().split()]
    maxi=max1(a)
    ans,ele=0,0
    if a[n-1]!=a[maxi]:
        ele=n-1
        ans+=1
    else:
        print('0')
        continue
    for j in range(n-2,maxi,-1):
        if a[j]>a[ele]:
            ele=j
            ans+=1
    print(ans)
