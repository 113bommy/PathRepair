n = int(input())
a = 2 * (n // 7)
b = a
m = n % 7
if m <= 6:
    b = b + min(m,2)
if m == 6:
    a = a + 1
print(a,b)
