# приезд генерала
len = int(input())
c = input().split()
for i in range(len):
    c[i] = int(c[i])
mn = min(c)
mx = max(c)
for j in reversed(range(len)):
    if c[j] == mn:
        a = (len - 1) - j
        break
for j in range(len):
    if c[j] == mx:
        b = j
        break

if a + b >= len:
    print(a + b - 1)
else:
    print(a + b)
