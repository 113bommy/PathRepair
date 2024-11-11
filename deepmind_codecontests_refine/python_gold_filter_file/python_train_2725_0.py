t = int(input())


def najdi_podpostupnost(n, d):
    mensie = []
    indexy_mensich = []
    vacsie = []
    vystup = n*[None]
    for j in range(n-1):
        if d[j+1] - d[j] < 0:
            mensie.append(d[j+1])
            indexy_mensich.append(j+1)
            vystup[j+1] = 1
            if len(mensie) > 1 and mensie[-1] < mensie[-2]:
                return "-"
    if len(mensie) < 1:
        return n*[1]
    for j in range(indexy_mensich[0]):
        if d[j] <= mensie[0]:
            vystup[j] = 1
        else:
            vystup[j] = 2
            vacsie.append(d[j])
    for j in range(len(mensie)-1):
        for k in range(indexy_mensich[j] + 1, indexy_mensich[j+1]):
            if d[k] > d[indexy_mensich[j+1]]:
                vacsie.append(d[k])
                vystup[k] = 2
                if vacsie[-1] < vacsie[-2]:
                    return "-"
            else:
                vystup[k] = 1
    for j in range(indexy_mensich[-1], n):
        if d[j] >= vacsie[-1]:
            vystup[j] = 2
        else:
            vystup[j] = 1
            mensie.append(d[j])
    if mensie[-1] <= vacsie[0]:
        return vystup
    else:
        return "-"
    

for i in range(t):
    n = int(input())
    d = [int(x) for x in list(input())]

    v = najdi_podpostupnost(n, d)
    if v == "_":
        print(v)
    else:
        print("".join([str(x) for x in v]))

 
            
                
