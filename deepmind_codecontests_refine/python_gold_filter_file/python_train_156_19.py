import math
s = input()
n = int(s.split()[0])
k = int(s.split()[1])
s = input()
arr = s.split()
for i in range(0, n):
    arr[i] = int(arr[i])
q = math.ceil((8 * k + 1) ** 0.5) // 2
print(arr[k - 1 - (q * (q - 1) // 2)])
