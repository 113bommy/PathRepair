n,k = map(int, input().split())
if not n&1 and k!=1:
    print('No')
else:
    d = {}
    i,f = 1, True
    while i <= k:
        if (n%i) in d:
            f = False
            break
        else:
            d[(n%i)] = 1
        i += 1
    print('Yes' if f else 'No')
