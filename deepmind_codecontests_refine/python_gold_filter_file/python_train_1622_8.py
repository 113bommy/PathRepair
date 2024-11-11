n=int(input())
lst = list(map(int, input().strip().split(' ')))
if sum(lst)!=0:
    print('YES')
    print(1)
    print(1,n,end=" ")
elif lst.count(0)==n:
    print('NO')
elif lst.count(0)==0:
    print('YES')
    print(n)
    for j in range(n):
        print(j+1,j+1,end=" ")
        print()
else:
    print('YES')
    print(2)
    for j in range(n):
        if sum(lst[:j])!=0 and sum(lst[j:])!=0:
            print(1,j,end=" ")
            print()
            print(j+1,n,end=" ")
            print()
            break