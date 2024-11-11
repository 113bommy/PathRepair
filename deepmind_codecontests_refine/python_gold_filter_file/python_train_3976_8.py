n = int(input())
for i in range(n):
    s, i, e = map(int, input().split())
    print(min(max(0, (s - i + e + 1) // 2), e + 1))