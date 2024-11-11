n, x = input().split()
n, x = int(n), int(x)

m1 = 2 ** 17
m2 = 2 ** 18

if n == 2 and x == 0:
    print("NO")
elif n == 1:
    a = [x]
elif n == 2 and x > 0:
    a = [0, x]
else:
    a = []
    ans = 0
    for i in range(1, n-2):
        ans ^= i
        a.append(i)
    if ans == x:
        a.append(m1)
        a.append(m2)
        a.append(m1+m2)
    else:
        a.append(m1)
        a.append(m1 ^ x ^ ans)
        a.append(0)
if not (n == 2 and x == 0):
    print("YES")
    print(" ".join([str(e) for e in a]))
