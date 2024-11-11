n = int(input())
s = input()
ans = 0
for i in range(1000):
    pw = str(i).zfill(3)
    idx = 0
    for c in s:
        if c == pw[idx]: idx += 1
        if idx == 3:
            ans += 1
            break
print(ans)