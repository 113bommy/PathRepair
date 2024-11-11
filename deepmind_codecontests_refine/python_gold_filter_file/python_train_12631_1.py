
__author__ = 'Esfandiar'

n,m = map(int,input().split())
F = '?'
for i in range(n):
    s = input()
    if len(set(s)) > 1 or s[0] == F:
        print('NO')
        exit()
    F = s[0]
print("YES")

