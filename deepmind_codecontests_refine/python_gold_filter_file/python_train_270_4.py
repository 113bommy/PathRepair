n = int(input())

c = 3
a = 1
b = 2

ans = "YES"

for i in range(n):
    x = int(input())

    if x == c:
        ans = "NO"

    if x == a:
        b, c = c, b
    elif x == b:
        a, c = c, a

print(ans)
