n, x, Decode = int(input()), input(), ''
if n % 2 == 0:
    for i in range(n):
        Decode = (Decode + x[i] if i % 2 != 0 else x[i] + Decode)
else:
    for i in range(n):
        Decode = (Decode + x[i] if i % 2 == 0 else x[i] + Decode)
print(Decode)
