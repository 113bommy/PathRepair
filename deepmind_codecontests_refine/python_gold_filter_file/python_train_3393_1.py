def f(x):
    #print('started')
    global n
    global a
    global b
    global l
   # print(a, b)
    for i in range(x, x + l):
        #print(i % (l + 1), i - x)
        if b[i % (l)] != a[i - x]:
            return False
    return True

import sys

n = int(input())
s = [input() for i in range(n)]
l = len(s[0])
answer = l * n
for i in range(n):
    a = s[i]
    ans = 0
    for j in range(n):
        b = s[j]
        for q in range(l):
            if f(q):
                ans += q
               # print(ans)
                break
        else:
            print(-1)
            sys.exit(0)
    answer = min(answer, ans)
print(answer)
        