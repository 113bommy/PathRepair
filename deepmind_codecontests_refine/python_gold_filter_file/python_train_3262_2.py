n, b = map(int, input().split())

arr = list(map(int, input().split()))
mx = max(arr)

suma = 0
for elem in arr:
    suma += elem

suma += b
suma /= n

if suma < mx:
    print(-1)
    exit()

else:
    for elem in arr:
        print("{0:0.6f}".format(suma - elem))


