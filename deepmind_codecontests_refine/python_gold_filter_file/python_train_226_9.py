def kek(A1, A2):
    d1 = {}
    d2 = {}
    for a in A1:
        if a in d1:
            d1[a] += 1
        else:
            d1[a] = 1
    for a in A2:
        if a in d2:
            d2[a] += 1
        else:
            d2[a] = 1
    return d1 == d2
l , m = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
D1 = {}
D2 = {}
for a in A:
    if a in D1:
        D1[a] += 1
    else:
        D1[a] = 1
for a in B:
    if a in D2:
        D2[a] += 1
    else:
        D2[a] = 1
W = []
for key in D2:
    if D2[key] == D1[A[0]]:
        W.append(key)
def Lol(W, A, B, m):
    for key in W:
        B2 = list(B)
        for i in range(len(B2)):
            B2[i] = (B2[i] + (- key + A[0])) % m
        if kek(A, B2):
            return (key - A[0] + m) % m
print(Lol(W, A, B, m))