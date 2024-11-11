a, b, c = map(int, input().split())
d, e, f = map(int, input().split())
n = int(input())

print("YES" if (a + b + c + 4) // 5 + (d + e + f + 9) // 10 <= n else "NO")
