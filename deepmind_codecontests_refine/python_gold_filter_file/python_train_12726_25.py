for _ in range(int(input())):
    n,m=[int(x) for x in input().split()]
    if n==1:
        print(0)
    if n==2:
        print(m)
    if n>=3:
        if m%2==0:
            half=m//2
            print(half*4)
        else:
            half=m//2
            halfnext=half+1
            ans=half*2 + halfnext*2
            print(ans)