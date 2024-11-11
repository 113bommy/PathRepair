def s(a, b):
    if (len(a) == len(b)):
        return a
    elif len(a) < len(b):
        return a
    else: return b
a, b = map(int, input().split())
dic = dict()
for i in range(b):
    m, n = input().split()
    dic[m] = s(m, n)
for i in input().split():
    print(dic[i], end = " ")