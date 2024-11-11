for _ in range(int(input())):
    n=int(input())
    a=list(map(int,input().split()))
    if a[0]<a[n-1]:
        print("YES")
    else:
        print("NO")