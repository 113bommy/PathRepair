n, a, b = map(int, input().split())
t = list(map(int, input().split()))
one, ans = 0, 0

for i in t:
    if i == 1:
        if a > 0:
            a -= 1
        elif b > 0:
            one += 1
            b -= 1
        elif one > 0:
            one -= 1
        else:
            ans += 1
    elif i == 2:
        if b > 0:
            b -= 1
        else:
            ans += 2

print(ans)
