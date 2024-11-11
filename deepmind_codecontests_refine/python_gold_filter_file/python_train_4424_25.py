s = input()

n = len(s)
r = "NO"

for i in range(0, n):
    for j in range(i, n):
        w = s[0:i] + s[j+1:]
        if w == "CODEFORCES":
            r = "YES"

print(r)