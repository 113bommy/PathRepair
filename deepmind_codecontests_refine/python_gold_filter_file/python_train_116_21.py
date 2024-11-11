n = int(input())
u = list(input())
u1 = sorted(u)
if u == u1:
    print("NO")
else:
    print("YES")
    a = 0; b = 0
    for i in range(n):
        if ord(u[i]) > ord(u1[i]):
            a = i
            break
    for i in range(a + 1, n):
        if ord(u[i]) < ord(u[a]):
            b = i
            break
    print(a + 1, b + 1)
        
