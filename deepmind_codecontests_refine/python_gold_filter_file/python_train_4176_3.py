def nod(a, b):
    if(a == 0 or b == 0):
        return a + b
    if(a > b):
        return nod(b, a % b)
    else:
        return nod(a, b % a)



n, m, k = map(int, input().split())
n2 = n // nod(n, k)
k = k // nod(n, k)
m2 = m // nod(m, k)
k = k // nod(m, k)
if(k > 2):
    print("NO")
else:
    if(k == 1):
        if(n2 < n):
            n2 = n2 * 2
        else:
            m2 = m2 * 2
    print("YES")
    print(0, 0)
    print(n2, 0)
    print(n2, m2)
