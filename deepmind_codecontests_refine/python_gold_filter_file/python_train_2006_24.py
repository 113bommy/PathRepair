for t in range(int(input())):
    n,k=[int(i) for i in input().split()]
    if n<k:
        print(abs(n-k))
    elif n%2==k%2:
        print(0)
    else:
        print(1)