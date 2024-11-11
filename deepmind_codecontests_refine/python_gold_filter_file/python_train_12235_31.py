n = int(input())
u = ((4 * 3 * (4**(n-3))) * 2)
if n > 3:
    u += 4 *(n-3) * 9 * (4**(n-4))
print(u)
