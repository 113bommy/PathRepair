t = int(input())
C = []
for j in range(t):
    s = input()
    nB = 0
    i = 0
    flag = 0
    while i < len(s):
        if s[i] == 'B':
            if flag != 0:
                flag -= 1
            else:
                nB += 1
            i += 1
        else:
            t = i+1
            flag += 1
            while t < len(s) and s[t] == 'A':
                t += 1
                flag += 1         # количество подряд идущих A
            i = t

    if flag == 0:
        C.append(nB % 2)
    else:
        C.append(nB % 2 + flag)

for i in range(len(C)):
    print(C[i])