T = input()
P = input()
tmp2 = []
for i in range(len(T)):
    tmp = T[i:].find(P)
    if tmp != -1:
        tmp2.append(len(T[:i])+tmp)
for s in sorted(set(tmp2)):
    print(s)