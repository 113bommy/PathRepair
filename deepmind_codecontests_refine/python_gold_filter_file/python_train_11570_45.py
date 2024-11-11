n = int(input())
for i in range(n):
    tmp = int(input())
    ans = tmp // 7 + (1 if tmp % 7 != 0 else 0)
    print(ans)
