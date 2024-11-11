n = int(input())
m = [input() for _ in range(2*n-2)]
c1 = max(m, key=len)
j = m.index(c1)
c2 = m[[i for i in range(2*n-2) if len(m[i])==len(c1) and i!=j][0]]
cand = [c1[:n-len(c2)] + c2, c2[:n-len(c1)] + c1]
sol = ['','']
chk = [{},{}]
for i in m:
    for j in range(2):
        if sol[j]!='-1':
            if cand[j].startswith(i) and cand[j].endswith(i):
                if len(i) not in chk[j]:
                    sol[j] += 'S'
                    chk[j][len(i)] = 1
                else:
                    sol[j] += 'P'
            elif cand[j].startswith(i):
                sol[j] += 'P'
            elif cand[j].endswith(i):
                sol[j] += 'S'
            else:
                sol[j] = '-1'
for i in range(2):
    if len(sol[i])==2*n-2 and sol[i].count('S') == sol[i].count('P'):
        print(sol[i])
        break
