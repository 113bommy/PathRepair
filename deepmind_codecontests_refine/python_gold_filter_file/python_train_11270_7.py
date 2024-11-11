t=int(input())
for i in range(t):
    n=int(input())
    k=0
    a=[int(j) for j in input().split()]
    for j in range(1,n-1):
        if a[j]>a[j+1] and a[j]>a[j-1]:
            k=1
            print("YES")
            print(j,j+1,j+2)
            break
    if k==0:
        print("NO")
            