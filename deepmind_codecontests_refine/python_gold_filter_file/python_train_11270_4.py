def sol(lis):
    for i in range(1,len(lis)-1):
        if lis[i]>lis[i-1] and lis[i]>lis[i+1]:
            return [i-1,i,i+1]
    return False
k = int(input())
for i in range(k):
    input()
    lis = list(map(int,input().split(' ')))
    lis = sol(lis)
    if lis:
        print('YES')
        for j in lis:
            print(j+1,end=' ')
        print()
        continue
    print('NO')
