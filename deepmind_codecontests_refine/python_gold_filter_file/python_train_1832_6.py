s = list(input())

i = 0
k = len(s) // 2
c = 0
while i < k:
    if s[i] != s[len(s) - 1 - i]:
        c += 1
    i += 1

if c == 1:
    print("YES")
elif c == 0 and len(s) % 2 == 1:
    print("YES")
else:
    print("NO")
