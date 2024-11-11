n = int(input())
s = [input() for _ in range(n)]

ans = 0
a = 0
for b in range(n):
    flag = 0
    for i in range(n):
        if flag == 1:
            break
        for j in range(n):
            if s[(i+a)%n][(j+b)%n] != s[(j+a)%n][(i+b)%n]:
                flag = 1
                break
    else:
        ans += n

print(ans)