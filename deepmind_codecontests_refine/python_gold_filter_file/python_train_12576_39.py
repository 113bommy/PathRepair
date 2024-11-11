n = int(input())
s = [input() for _ in range(n)]
ans = 0
w = 0
a = 0
b = 0

for c in s:
    ans += c.count("AB")
    if c[0] == "B" and c[-1] == "A":
        w += 1
    elif c[0] == "B":
        b += 1
    elif c[-1] == "A":
        a += 1

if a == b == 0:
    w -= 1
ans += max(w,0) + min(a,b)
print(ans)