def gcd(a, b):
    x, y = [a, b] if a > b else [b, a]
    while y:
        x, y = y, x%y
    return x

def solve(a, b):
    if b == 1:
        return 0, 1
    elif a == 1:
        return 1, 0

    A, B, Q, R = [a], [b], [b//a], [b%a]
    i = 0
    while R[i] != 0:
        B.append(A[i])
        A.append(R[i])
        Q.append(B[i+1]//A[i+1])
        R.append(B[i+1]%A[i+1])
        i += 1

    x, y = -1*Q[len(Q)-2], 1
    for i in range(len(A)-3, -1, -1):
        x, y = y - x*Q[i], x

    return x, y

a, b = list(map(int, input().split(' ')))
c = gcd(a, b)
a, b = a//c, b//c

x, y = solve(a,b)
print(x, y)
