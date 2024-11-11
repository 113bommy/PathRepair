N, K = input().split()
D = list(map(int, input().split()))

for i in range(0, 10):
    if i in D:
        D.remove(i)
    else:
        D.append(i)

digit = len(N)
con = ''

for i in range(digit):
    if int(N[i]) in D:
        con += N[i]

    else:
        flag = True
        for j in D:
            if j > int(N[i]):
                N = con + str(j) + str(D[0]) * (digit-len(con)-1)
                flag = False
                break

        if flag:
            if D[0] == 0:
                N = str(D[1]) + str(D[0]) * digit
            else:
                N = str(D[0]) * (digit+1)

        break

print(N)
