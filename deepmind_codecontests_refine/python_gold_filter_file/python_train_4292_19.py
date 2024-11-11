t = int(input())
import math
while t:
    n = int(input())
    s = int(math.sqrt(n) + 10)
    ans = []
    for i in range(s)[2:]:
        if n % i == 0 and len(ans) < 2:
            ans.append(i)
            n //= i
    if len(ans) == 2 and ans[1] < n:
        ans.append(n)
    if len(ans) == 3:
        print("YES")
        print(ans[0], ans[1], ans[2], sep=' ')
    else:
        print("NO")
    t -= 1
