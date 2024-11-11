def solve():
    n=int(input())
    a=list(map(int,input().split()))
    cl=['odd','even']
    m=int(input())
    ans=True
    b=[]
    ap=b.append
    for i in range(n):
        for j in range(i):
            if a[j]>a[i]:
                ans=not ans

    for i in range(m):
        left,right=map(int,input().split())
        if ((right-left+1)//2)%2 == 1:
            ans=not ans
        ap(cl[ans])
    print('\n'.join(b))
solve()