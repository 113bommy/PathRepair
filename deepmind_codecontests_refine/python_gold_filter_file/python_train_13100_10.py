n = int(input())
a = sorted(list(map(int, input().split())), reverse=True)
swi = 0
s = [0, 0]
i = 0
while i < len(a) - 1:
    if a[i] == a[i + 1]:
        s[swi] = a[i]
        i += 1
        swi += 1
        if swi == 2:
            break
    i += 1

print(s[0] * s[1])
