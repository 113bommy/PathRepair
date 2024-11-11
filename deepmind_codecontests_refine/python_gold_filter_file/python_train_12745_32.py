_ = input().strip().split(' ')
n = int(_[0])
p = int(_[1])
k = int(_[2])
# print(n, p, k)
cnt = p - k
if cnt < 1:
    while cnt < 1:
        cnt += 1
if cnt != 1:
    print('<< ',end='')
while cnt <= n and cnt <= (p + k):
    if cnt == p:
        print('(%d) '%cnt, end='')
    else:
        print(cnt, end=' ')
    cnt += 1
if cnt-1 != n:
    print('>>')