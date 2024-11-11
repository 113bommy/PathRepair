from collections import Counter
for ii in range(int(input())):
    n=int(input())
    a = list(map(int, input().split()))
    co = Counter(a)
    hco = co.most_common(1)[0][1]
    l=list(dict(co).values()).count(hco)
    print(((n-l)//(hco-1))-1)