'''
f[i] = f[i - 1] - f[i - 2]
f[i] = -f[i - 3]
f[i] = -f[i - 4] + f[i - 5]
f[i] = f[i - 6]
'''

m = list(map(int, str.split(input())))
for _ in range(2, 6):

    m.append(m[-1] - m[-2])

print(m[(int(input()) - 1) % 6] % (10 ** 9 + 7))
