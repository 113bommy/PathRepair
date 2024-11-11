n = int(input())
k = int(((-1 + (8 * n + 1) ** 0.5) / 2))
somme = k * (k + 1) // 2
if n == somme:
    print(k)
else:
    print(n - somme)