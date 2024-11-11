n, m = map(int, input().split())

answer = True
for i in range((n - 1) // 2 + 1, n + 1):
    if i % m == 0:
        print(i)
        answer = False
        break

if answer:
    print(-1)
