# HEY STALKER
for _ in range(int(input())):
    n, m, x, y = map(int, input().split())
    l = []
    for t in range(n):
        kl = list(input())
        l.append(kl)
    if x <= (y/2):
        cnt = 0
        for t in l:
            for p in t:
                if p == '.':
                    cnt += 1
        print(cnt*x)
    else:
        ans = 0
        for t in range(n):
            cnt = 0
            for i in range(m):
                if l[t][i] == '.':
                    cnt += 1
                if l[t][i] == '*' and cnt != 0:
                    ans += y*(cnt//2)
                    if cnt % 2:
                        ans += x
                    cnt = 0
            ans += y*(cnt//2)
            if cnt % 2:
                ans += x
        print(ans)