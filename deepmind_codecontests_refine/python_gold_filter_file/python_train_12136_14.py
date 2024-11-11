n = int(input())
e = str(input())
s = []
for i in range(n):
    s.append(' ')

l = r = n//2 - 1 if n % 2 == 0 else n//2
s[l] = e[0]

for k in range(n - 1):

    if k % 2 == n % 2:
        s[r + 1] = e[k + 1]
        r += 1
    else:
        s[l - 1] = e[k + 1]
        l -= 1

print(''.join(s))
