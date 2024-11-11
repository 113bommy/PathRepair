pow3 = [pow(3, x) for x in range(40)][::-1]
sum_pow3 = sum(pow3)

nb = int(input())
for _ in range(nb):
    curr = int(input())
    sums = sum_pow3
    for i in pow3:
        if sums - i >= curr:
            sums -= i
        #print(sums)
    print(sums)


