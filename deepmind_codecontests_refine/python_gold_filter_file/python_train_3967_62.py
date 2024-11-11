n, m = map(int, input().split())
a = [9]
b = [1]
asum = 9
bsum = 1
while min(asum, bsum) < n:
    asum += 9
    bsum += 9
    a.append(0)
    a.append(9)
    b.append(9)
    b.append(0)

if b[-1] == 0:
    b.pop()

print(''.join(str(x) for x in reversed(a)))
print(''.join(str(x) for x in reversed(b)))
