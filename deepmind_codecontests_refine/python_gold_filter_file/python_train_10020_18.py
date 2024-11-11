from collections import Counter
T = int(input().strip())
for t in range(T):
    hh = Counter()
    n, x = list(map(int, input().split()))
    for i in range(n-1):
        a, b = list(map(int, input().split()))
        hh[a] += 1
        hh[b] += 1
    if hh[x] <=1:
        print('Ayush')
    elif n % 2:
        print('Ashish')
    else:
        print('Ayush')
