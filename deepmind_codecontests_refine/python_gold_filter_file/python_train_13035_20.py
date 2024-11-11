for _ in range(int(input())):
    n,s,k=map(int,input().split())
    ls=[int(a) for a in input().split()]
    ls.sort()
    for i in range(1002):
        if s-i not in ls and s-i>0:
            print(i)
            break
        if s+i not in ls and s+i<=n:
            print(i)
            break