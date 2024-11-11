for tc in range(int(input())):
    n = int(input())
    if n <= 3:
        print(-1)
    else:
        if n%2:
            o=n
        else:
            o=n-1
        ans = []
        while o >= 5:
            ans.append(o)
            o-=2
        ans += [2,4,1,3]
        o = 6
        while o <= n:
            ans.append(o)
            o+=2
        print(*ans)