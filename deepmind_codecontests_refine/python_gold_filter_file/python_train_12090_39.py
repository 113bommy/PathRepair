nb_qry = int(input())
for _ in range(nb_qry):
    l, r = [int(x) for x in input().split()]
    begin = 2
    while True:
        if l * begin <= r:
            print(l,l * begin)
            break
        begin += 1
