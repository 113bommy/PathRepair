for _ in range(int(input())):
    n=int(input())
    c=0
    a=list(map(int,input().split()))
    for i in range(n-1):
        if abs(a[i]-a[i+1])>=2:
            c+=1
            print("YES")
            print(i+1,i+2)
            break
    if c==0:
        print("NO")


