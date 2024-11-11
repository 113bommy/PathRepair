t = int(input())

for _ in range(t):
    sosu = [int(i) for i in input().split()]

    sosu.sort(reverse=True)

    if sosu[0] != sosu[1]:
        print('NO')
    else:
        print('YES')
        print(sosu[1],sosu[2],1)




