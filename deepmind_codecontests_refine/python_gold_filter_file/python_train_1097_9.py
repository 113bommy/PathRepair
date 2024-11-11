t = int(input())
s = [0 for i in range(3)]
for i in range(t):
    m =  [int(i) for i in input().split()]
    for j in range(3):
        s[j] += m[j]
if s[0] == s[1] == s[2] == 0:
    print('YES')
else:
    print('NO')