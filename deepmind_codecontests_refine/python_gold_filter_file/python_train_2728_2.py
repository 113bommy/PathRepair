for _ in range(int(input())):
    n=int(input())
    a=list(map(int,input().split()))
    f=1
    for i in range(n-1):
        if abs(a[i+1]-a[i])>1:
            print("YES")
            print(i+1,i+2)
            f=0; break
    if f: print("NO")