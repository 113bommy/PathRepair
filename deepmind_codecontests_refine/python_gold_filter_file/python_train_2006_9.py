for _ in range(int(input())):
    n,k = map(int,input().split())
    if n>=k:
        if n%2==k%2:
            print(0)
        else:
            print(1)
    else:
        print(abs(k-n))