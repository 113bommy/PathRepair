N, Q = map(int, input().split())
s = input()

X = []
for i in range(Q):
    t, d = input().split()
    if d == 'L':
        X.append([t, -1])
    else:
        X.append([t, 1])
        
def check(m):
    i = m
    for x in X:
        if x[0] == s[i]:
            i += x[1]
            if i < 0:
                return -1
            if i >= N:
                return 1
    return 0

L, R = -1, N
while R - L > 1:
    M = (L + R) // 2
    if check(M) < 0:
        L = M
    else:
        R = M  
A = L

L, R = -1, N
while R - L > 1:
    M = (L + R) // 2
    if check(M) > 0:
        R = M
    else:
        L = M
B = R

print(B - A - 1)