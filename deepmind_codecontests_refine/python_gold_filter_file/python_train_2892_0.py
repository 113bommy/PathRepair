def rev(a):
    L = []
    for i in range(N):
        L.append(a % 3)
        a //= 3
    return int("".join(map(str, L)), 3)
    
def salsa():
    lazy[0] *= -1

def rumba():
    i = 0
    for k in range(N):
        if lazy[i] < 0:
            lazy[3*i+1] *= -1
            lazy[3*i+2] *= -1
            lazy[3*i+3] *= -1
            lazy[i] = 1
            value[3*i+1] ^= 3
            value[3*i+2] ^= 3
            value[3*i+3] ^= 3
        value[3*i+1] += 1
        value[3*i+2] += 1
        value[3*i+3] += 1
        value[3*i+1] %= 3
        value[3*i+2] %= 3
        value[3*i+3] %= 3
        i = 3 * i + (1 if value[3*i+1] == 0 else 2 if value[3*i+2] == 0 else 3)

def calcall():
    a = 1
    i = 0
    for k in range(1, N + 1):
        for _ in range(3 ** k):
            i += 1
            if lazy[(i-1)//3] < 0:
                lazy[i] *= -1
                if value[i]: value[i] ^= 3
            value[i] = value[i] * a + value[(i-1) // 3]
        a *= 3
        
N = int(input())
NN = 3 ** (N + 1) // 2
value = [(i-1) % 3 if i else 0 for i in range(NN)]
lazy = [1 for i in range(NN)]

for t in input():
    if t == "R":
        rumba()
    else:
        salsa()

calcall()

ANS = [0] * (3 ** N)
for i in range(3 ** N):
    ANS[rev(i)] = value[i + (NN - 1) // 3]

print(*ANS)