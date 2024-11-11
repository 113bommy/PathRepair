k = int(input())
n = [int(x) for x in list(input())]
total = 0
n.sort()
for d in n:
    total += d
if total >= k:
    print(0)
else:
    ans = 0
    left = k - total
    while left > 0:
        if ans == len(n):
            break
        left -= (9 - n[ans])
        ans += 1
    print(ans)