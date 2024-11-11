tmp = input().split()
n = int(tmp[0])
k = int(tmp[1])
s = input()
alf = 'abcdefghijklmnopqrstuvwxyz'
flag = 0
for i in alf:
    if s.count(i) > k:
        flag += 1
if flag == 0:
    print('YES')
else:
    print('NO')