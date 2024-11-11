n = int(input())
s = input().split()
if len(s) == 1 and s.count('0') == 1:
    print('NO')
elif len(s) > 1 and s.count('0') != 1 :
    print('NO')
else:
    print('YES')