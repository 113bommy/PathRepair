from sys import exit

def blokovi(x):
    ret = [0]
    for i in range(len(x) - 1):
        if x[i] != x[i + 1]:
            ret.append(i + 1)
    return ret + [len(x)]

s = input()
t = input()

ss = blokovi(s)
tt = blokovi(t)

if s[-1] == 'a':
    s += 'b'
else:
    s += 'a'

if t[-1] == 'a':
    t += 'b'
else:
    t += 'a'

def greedy(x, y, rev=False):
    i, j = len(x) - 1, len(y) - 1
    swaps = []
    while True:
        while i >= 0 and x[i] == 'a':
            i -= 1
        while j >= 0 and y[j] == 'b':
            j -= 1
        if i < 0 and j < 0:
            break
        x, y = y, x
        if rev:
            swaps.append((j + 1, i + 1))
        else:
            swaps.append((i + 1, j + 1))
        i, j = j, i
    return swaps

def solve(x, y):
    p = greedy(x, y)
    q = greedy(y, x, True)
    if len(p) < len(q):
        return p
    return q

probao = set()

total = len(ss) + len(tt)
sol = solve(s[:-1], t[:-1])
for b, i in enumerate(ss):
    for c in range((2 * b + len(tt) - len(ss)) // 2 - 2, (2 * b + len(tt) - len(ss) + 1) // 2 + 3):
        if 0 <= c < len(tt):
            j = tt[c]
            bs = b + len(tt) - c - 1
            bt = c + len(ss) - b - 1
            if abs(bs - bt) > 2:
                continue
            proba = (bs, bt, s[i], t[j])
            if proba in probao:
                continue
            probao.add(proba)
            s2 = t[:j] + s[i:-1]
            t2 = s[:i] + t[j:-1]
            if i + j > 0: 
                if i + j == len(s) + len(t) - 2:
                    cand = solve(t2, s2)
                else:
                    cand = [(i, j)] + solve(s2, t2)
            else:
                cand = solve(s2, t2)
            if len(cand) < len(sol):
                sol = cand

print(len(sol))
for i, j in sol:
    print(i, j)
