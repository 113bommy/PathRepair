
n = int(input())
pos_actual = 1
rpta = ''
for i in range(n-1):
    pos_actual = ((pos_actual + i) % n) +1
    rpta = rpta + str(pos_actual)
    if i < n-1:
        rpta = rpta + ' '
print(rpta)