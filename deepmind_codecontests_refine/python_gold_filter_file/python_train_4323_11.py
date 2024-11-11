n = int(input())

ans = list()
for i in range(n):
    ans.append(1)

    while len(ans) > 1 and ans[-1] == ans[-2]:
        t = ans.pop()
        ans[-1] = t + 1

print(' '.join(map(str, ans)))
