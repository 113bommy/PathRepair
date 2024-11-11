n = int(input())
s = list(input())
ans = 0
for i in range(1000):
    pin = list(str(i).zfill(3))
    idx = 0
    for c in s:
        if c == pin[idx]:
            idx += 1
        if idx == 3:
            ans += 1
            break
print(ans)