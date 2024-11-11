n = int(input())
x = 1234567
y = 123456
z = 1234

aRange = int(n / x)
yes = False

for a in range(aRange+1):
    bRange = int((n - a*x) / y)
    for b in range(bRange+1):
        if (n - a*x - b*y) % z == 0:
            yes = True
            break

if yes:
    print("YES")
else:
    print("NO")
