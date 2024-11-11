n = int(input())
a = sorted(map(int, input().split()))
ans = 1
for i in a:
    ans *= i
    if ans > 10 ** 18:
        print(-1)
        exit()
print(ans)