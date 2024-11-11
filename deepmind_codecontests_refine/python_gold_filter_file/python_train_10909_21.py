N = int(input())
S = input()

ans = 0
for num in range(1000):
    target = str(num).zfill(3)
    cur = 0
    for s in S:
        if s == target[cur]:
            cur += 1
        if cur == 3:
            ans += 1
            break
print(ans)
