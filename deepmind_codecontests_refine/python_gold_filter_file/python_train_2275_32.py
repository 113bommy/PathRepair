N = int(input())
A = [int(j) for j in input().split()]

if sum(A)%2==0:
    print('YES')
else:
    print('NO')