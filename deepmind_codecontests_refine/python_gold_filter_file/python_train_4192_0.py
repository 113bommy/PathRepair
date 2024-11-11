t = int(input())
resposta = []

for k in range(t):
    n, m = map(str,input().split())
    n = int(n)
    m = int(m)

    a = input().split()
    vec_a = []
    vec_a2 = []
    for i in range(n):
        vec_a.append(int(a[i]))
        vec_a2.append(int(a[i]))
    vec_a = sorted(vec_a)
    vec_a2 = sorted(vec_a2)  # el que queda revertit

    w = input().split()
    vec_w = []
    vec_w2 = []
    for i in range(m):
        vec_w.append(int(w[i]))
        vec_w2.append(int(w[i]))
    vec_w = sorted(vec_w)
    vec_w2 = sorted(vec_w2)

    for i in range(m):
        vec_w2[i] = vec_w[m - 1 - i]

    for i in range(n):
        vec_a[i] = vec_a2[n - 1 - i]


    # punt = 0
    # compt = 0
    # for i in range(m):
    #     if vec_w[i] == 1:
    #         punt += 2 * vec_a[compt]
    #         compt += 1
    #     else: 
    #         punt += vec_a[compt]
    #         compt += 1

    # compt = 0
    # for i in range(m):
    #     if vec_w2[i] > 1:
    #         punt += vec_a2[compt]
    #         compt += 1

    punt = 0
    n1 = vec_w.count(1)
    nelse = m - n1

    for i in range(n1):
        punt += 2 * vec_a[i]
    
    for i in range(n1, n1 + nelse):
        punt += vec_a[i]
    
    # la part de màxims està ben feta. Ara mínims. Començar pels grups grans

    compt = 0
    for i in range(m):
        if vec_w2[i] > 1:
            punt += vec_a2[compt]
            compt += vec_w2[i] - 1

    resposta.append(punt)

for i in range(t):
    print(resposta[i])