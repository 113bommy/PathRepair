a, b, c = map(int, input().split())
ans = 0

while a % 2 == 0 and b % 2 == 0 and c % 2 == 0:
    if a == b == c:
        print(-1)
        exit()
    a, b, c = (b + c) // 2, (c + a) // 2, (a + b) // 2
    ans += 1
print(ans)
