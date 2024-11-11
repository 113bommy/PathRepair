n, m = map(int, input().split())
cena = 100000
for i in range(0, n):
    a, b = map(int, input().split())
    novcena = a / b
    if novcena < cena:
        cena = novcena
print(cena * m)
