n = int(input())
a = [n]
if n != 2:
    a.append(n - 1)

def div_(N, k):
    while N % k == 0:
        N /= k
    if N % k == 1:
        a.append(k)

for k in range(2, int(n ** 0.5) + 1):
    if n % k == 0:
        div_(n,k)
        if k != n / k:
            div_(n, n // k)

    if (n - 1) % k == 0:
        a.append(k)
        if k != (n - 1) / k:
            a.append((n - 1) // k)

print(len(a))