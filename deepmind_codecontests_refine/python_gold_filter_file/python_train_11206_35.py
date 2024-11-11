numbers = [int(n) for n in input().split()]

n, k = numbers

remainders = []
for d in range(1, k+1):
    res = n % d
    if res not in remainders:
        remainders.append(res)
    else:
        print('No')
        exit()

print('Yes')
