n = int(input())

cnt = 0
ans = 0

for i in range(0, 10**7):
    cnt += 3 * i + 2
    if cnt > n:
        break
    elif (n - cnt) % 3 == 0:
        ans += 1

print(ans)
