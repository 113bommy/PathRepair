c=int(input())
for _ in range(c):
    n,k=map(int,input().split())
    if n%2==0 and k%2==0:
        if n<k:
            print("NO")
            continue
        else:
            print("YES")
            for _ in range(k-1):
                print(1)
            print(n-k+1)
    elif n%2==1 and k%2==1:
        if n<k:
            print("NO")
            continue
        else:
            print("YES")
            for _ in range(k-1):
                print(1)
            print(n-k+1)
    elif n%2==0 and k%2==1:
        if n<2*k:
            print("NO")
            continue
        else:
            print("YES")
            for _ in range(k-1):
                print(2)
            print(n-2*k+2)
    else:
        print("NO")