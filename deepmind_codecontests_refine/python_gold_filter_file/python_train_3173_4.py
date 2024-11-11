n, k = map(int, input().split())
list1 = list(map(int,input().split()))
minn = 100000
maxx = 0
for i in range(n):
    if list1[i] > maxx:
        maxx = list1[i]
    if list1[i] < minn:
        minn = list1[i]
    
if maxx - minn > k:
    print('NO')
else:
    print('YES')
    for i in range(n):
        for j in range(list1[i]):
            print((j%k)+1, end= ' ')
        
        print('')