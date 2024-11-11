N = int(input())
S = input()
ans = 0
for i in range(1000):
    e = str(i).zfill(3)
    c = 0
    for s in S:
        if s == e[c]:
            c += 1
            if c == 3:
                ans += 1
                break
print(ans)