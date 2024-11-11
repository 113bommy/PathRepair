def find():
    n, m = map(int, input().split())
    mas = [tuple(map(int, input().split())) for i in range(n)]
    for i in range(n):
        for j in range(m):
            if (j + i) % 2 == 0:
                print(720720, end=' ')
            else:
                print(720720 + mas[i][j]**4, end=' ')
        print()


find()