n, a, b = map(int, input().split())
line = list(map(int, input().split()))
ans = 0
c = 0

for i in line:
    if i == 1:
        if a > 0:
            a -= 1
        else:
            if b > 0:
                b -= 1
                c += 1
            else:
                if c > 0:
                    c -= 1
                else:
                    ans += 1
    else:
        if b > 0:
             b -= 1
        else:
            ans += 2
print(ans)
