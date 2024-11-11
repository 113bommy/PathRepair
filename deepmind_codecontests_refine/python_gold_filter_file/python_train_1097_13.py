n = int(input())

s = [0,0,0]

for i in range(n):
    x1, x2, x3 = map(int, input().split())
    s[0] += x1
    s[1] += x2
    s[2] += x3
print("YES" if s[0] == 0 and s[1] == 0 and s[2] == 0 else "NO")
