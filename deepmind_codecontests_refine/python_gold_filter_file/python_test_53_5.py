for _ in range(int(input())):
    n,c=map(str,input().split())
    n=int(n)
    s=input().strip('\n')
    if s.count(c)==n:
        print(0)
        continue
    f=-1
    for i in range(n-1,(n//2)-1,-1):
        if s[i]==c:
            f=i
            break
    if f!=-1:
        print(1)
        print(f+1)
    else:
        print(2)
        print(n,n-1)