for _ in range(int(input())):
    n,k=map(int,input().split())
    s=sorted([[int(i) for i in input().split()] for i in range(2)])
    g=s[1][0]-s[0][1];ans=int(1e20)
    if s[1][0] < s[0][1] and s[0][1] > s[1][1]:
        k -= (s[1][1] - s[1][0])*n
        mX = s[0][1] - s[0][0] - (s[1][1] - s[1][0])
        ans = min(k,mX*n) + max(0,2*(k-mX*n))
        print(max(0,ans))
        continue
    if -g*n>=k:
        print(0);continue
    mX=s[1][0]-s[0][0]+abs(s[1][1]-s[1][0])
    for i in range(1,n+1):ans=min(ans,g*i+min((mX)*i,k)+max(0,2*(k-(mX*i))))
    assert(ans > 0)
    print(ans)