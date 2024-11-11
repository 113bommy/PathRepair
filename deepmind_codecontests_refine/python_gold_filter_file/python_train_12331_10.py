a1,a2,a3 = map(int,input().split())
b1,b2,b3 = map(int,input().split())
n        = int(input())

a = a1 + a2 + a3
b = b1 + b2 + b3
shelf = a//5 + b//10 + (a % 5 != 0) + (b % 10 != 0)

print('YES' if (shelf <=n) else 'NO')