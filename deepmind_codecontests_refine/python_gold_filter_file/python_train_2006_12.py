t = int(input())
for i in range(t):
    n,k = map(int,input().split())
    if k%2:
        if n >= k:
            if n%2:
                print(0)
            else:
                print(1)
        else:
            print(k-n)

    else:
        if n>=k:
            if n%2:
                print(1)
            else:
                print(0)
        else:
            print(k-n)
