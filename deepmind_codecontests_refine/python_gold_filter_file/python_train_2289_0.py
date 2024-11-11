n = int(input())
bits_raw = input()
bits = [int(bits_raw[i]) for i in range(n)]
m = int(input())
ones = []
zeros = []
for i in range(n):
    if(bits[i] == 1):
        ones.append(i)
    else:
        zeros.append(i)
if(len(zeros) > m):
    for i in range(m):
        bits[zeros[i]] = 1
    print(''.join(map(str, bits)))
else:
    allone = [1 for i in range(n)]
    l = len(ones)
    for i in range(m - len(zeros)):
        allone[ones[l - i - 1]] = 0
    print(''.join(map(str, allone)))