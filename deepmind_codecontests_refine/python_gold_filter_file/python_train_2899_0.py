S = input()
P = list(set(S))
ANS = []
for i in range(len(P)) :
    T = list(S.split(P[i]))
    U = []
    for j in range(len(T)) :
        U.append(len(T[j]))
    ANS.append(max(U))
print(min(ANS))
