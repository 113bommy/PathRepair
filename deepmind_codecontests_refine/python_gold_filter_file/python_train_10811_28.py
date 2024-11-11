d = {"I": 1, "D": -1}
x = 0
N = int(input())
S = input()
ans = 0
for Si in S:
    x += d[Si]
    ans = max(ans, x)
print(ans)
