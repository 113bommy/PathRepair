def sum(a):
    s = 0
    for i in a:
        s += i
    return s

n, T = map(int, input().split())
a = list(map(int, input().split()))

sum = sum(a)

k = 0
k += n * (T // sum)
T %= sum

new_a = []
new_sum = 0
ch = True
while ch:
    for i in range(n):
        if a[i] <= T:
            new_a.append(a[i])
            new_sum += a[i]
            k += 1
            T -= a[i]

    n = len(new_a)

    if n == 0:
        ch = False
        break

    sum = new_sum
    a = new_a
    new_a = []
    new_sum = 0

    k += n * (T // sum)
    T %= sum


print(k)