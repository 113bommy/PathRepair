for _ in range(int(input())):
    n = int(input())
    a = list(map(int,input().split()))
    ans = []; val = 0
    for i in a:
        val ^= i
    if val > 0:
        ans.append(val)
        ans.append(sum(a)+val)
    else:
        ans.append(sum(a))
    print(len(ans))
    print(*ans)
