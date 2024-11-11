
def answer(n, m, a, b, c):
    new_ary = []
    for i in range(len(c)):
        indx = a.index(c[i])
        if len(a[indx]) <= len(b[indx]):
            new_ary.append(a[indx])
        else:
            new_ary.append(b[indx])

    return ' '.join(new_ary)

def answer2(c, d):
    new_ary = []
    for e in c:
        if len(e) <= len(d[e]):
            new_ary.append(e)
        else:
            new_ary.append(d[e])

    return ' '.join(new_ary)

def main():
    n, m = [int(i) for i in input().split()]
    a = ['x'] * m
    b = ['x'] * m
    d = {}
    for j in range(m):
        a[j], b[j] = [i for i in input().split()]
    d = {k:v for (k, v) in zip(a, b)}
    
    c = [i for i in input().split()]
    #print(d)
    #print(answer(n, m, a, b, c))
    print(answer2(c,d))

main()