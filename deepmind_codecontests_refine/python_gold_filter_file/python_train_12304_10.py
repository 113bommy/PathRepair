da, db = map(int, input().split())
if da == db:
    print(da, 1, ' ', da, 2, sep='')
elif db - da == 1:
    print(da, 9, ' ', db, 0, sep='')
elif da == 9 and db == 1:
    print(9, 10)
else:
    print(-1)