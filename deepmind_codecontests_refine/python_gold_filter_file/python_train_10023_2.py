for j in range(int(input())):
    n,m=map(int,input().split())
    s=0
    for i in range(n):
        q,w=map(int,input().split())
        e,r=map(int,input().split())
        if e==w:s=1
    print("YES" if s==1 and m%2==0 else "NO")