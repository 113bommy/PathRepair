varo = []
seqis = 0

for i in range(11):
    varo.append(int(input()))
    seqis += 1

for i in range(11):
    seqis -= 1
    a = abs(varo[seqis]) ** 0.5
    b = (varo[seqis] ** 3) * 5
    result = a + b

    if 400 > result:
        print("f(", varo[seqis], ') = ', '%.2f' % result, sep='')
    else:
        print("f(", varo[seqis], ") = MAGNA NIMIS!", sep='')

