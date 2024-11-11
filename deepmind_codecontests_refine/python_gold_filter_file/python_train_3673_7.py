from sys import stdin
input = stdin.readline

t = int(input())
for _ in range(t):
    n = int(input())
    s = input().strip()
    if not(">" in s) or not("<" in s):
        print(n)
        continue
    ans = 0
    for i in range(n):
        ans += "-" in (s[i], s[(i+1) % n])
    print(ans)