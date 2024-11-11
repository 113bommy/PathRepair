n = int(input())
S = input()
ans = 0
for i in range(1000):
    t = str(i).zfill(3)
    for s in S:
        if s == t[0]:
            t = t[1:]
        if t == '':
            ans += 1
            break
print(ans)