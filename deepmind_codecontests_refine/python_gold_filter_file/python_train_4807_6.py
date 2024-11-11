n = int(input())
a  = list(map(int,input().split()))
a.sort()
if a[n-1] >= a[n-2] + a[n-3] :
    print("NO")
else:
    print("YES")
    print(a[n-3],a[n-1],a[n-2],end=" ")
    for i in range(n-3):
        print(a[i],end=" ")