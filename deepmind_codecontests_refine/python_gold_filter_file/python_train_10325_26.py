'''B. Обнуление массива'''
n = int(input())
a = [int(i) for i in input().split()]
s1 = sum(a)
s2 = max(a)
s3 = s1 - s2
if s1%2!=0:
    print('NO')
elif s2>s3:
    print('NO')
else:
    print('YES')
