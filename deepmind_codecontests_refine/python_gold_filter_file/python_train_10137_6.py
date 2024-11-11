


n = int(input())
A = input()

if n == 1:
    tab = [A]
    i = n
elif n % 3 == 2:
    tab = [A[0:2]]
    i = 2
elif n % 3 == 1:
    tab = [A[0:2], A[2:4]]
    i = 4
else:
    i = 0
    tab = []

for j in range(i, n, 3):
    tab += [A[j:j+3]]

print('-'.join(tab))
