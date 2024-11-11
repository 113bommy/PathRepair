
k = int(input()) // 1
a = [2, 4]

for i in range(2):
    n = int(input()) // a[i]
    if (n < k) and (n != 0): k = n
    elif n == 0:
        print(0)
        break
else: print(k*7)