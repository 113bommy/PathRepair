N = int(input())
Ns = []
for n in range(N):
    Ns.append(int(input()))

for n in Ns:
    c = 0
    while n % 5 == 0:
        c += 3
        n = n // 5
        #print(str(n) +  ' 5s')
    while n % 3 == 0:
        c += 2
        n = n // 3
        #print(str(n) +  ' 3s')
    while n % 2 == 0:
        c += 1
        n = n // 2
        #print(str(n) +  ' 2s')

    if n == 1:
        print(c)
    else:
        print(-1)    