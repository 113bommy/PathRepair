
tmp = input().split()

n, m = int(tmp[0]), int(tmp[1])

cups = []

for i in input().split():
    cups.append(int(i))

cups.sort(reverse=True)

ans = n + 1

for i in range(1, n + 1):
    tmp_sum = 0
    for j in range(n):
        tmp_sum += max((cups[j] - int(j / i)), 0)
    if tmp_sum >= m:
        ans = i
        break

if ans == n + 1:
    print(-1)
else:
    print(ans)




