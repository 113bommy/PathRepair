for _ in range(int(input())):
    n=2*int(input())
    f=1
    for i in range(3,n+1):
        f=(f*i)%(10**9+7)
    print(f)