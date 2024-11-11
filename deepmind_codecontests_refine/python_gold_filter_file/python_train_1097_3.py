n = int(input())
a = []
total=0
count=0
for _ in range(n):
    a.append(list(map(int, input().rstrip().split())))
for j in range(3):
    for i in range(n):
        total+=a[i][j]
    if total==0:
        count+=1
if count==3:
    print('YES')
else:
    print('NO')