n=int(input())
a=[int(i) for i in input().split()]
od=[i for i in a if i%2]
print('YES' if len(od)%2==0 else 'NO')