n, k = [int(x) for x in input().split()]
if k > 1e6:
    print(-1)
    exit(0)
ind = -1
uwu = -1
for i in range(1, n + 1):
    if i*i > n:
        break
    if (n % i == 0):
        a1 = i;
        anmin1 = a1*(k - 1);
        an = n - ((a1+anmin1)*(k - 1) // 2);
        if (an > anmin1):
            ind = i;
            uwu = an;
        
        a1 = n / i;
        anmin1 = a1*(k - 1);
        an = n - ((a1+anmin1)*(k - 1) // 2);
        if (an > anmin1):
            ind = n // i;
            uwu = an;
            break
if ind == -1:
    print(-1)
    exit(0)
first = ind
for i in range(k - 1):
    print(first, end=' ')
    first += ind
print(int(uwu))