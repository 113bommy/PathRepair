a = input().split()
da = int(a[0])
db = int(a[1])
if da == 9 and db == 1:
    print(99, 100)
elif da == db:
    print(str(da) + '0', str(db) + '1')
elif db - da == 1:
    print(str(da) + '9', str(db) + '0')
else:
    print(-1)
