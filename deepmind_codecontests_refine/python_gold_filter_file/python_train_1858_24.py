h, w = map(int, input().split())
a = [input() for _ in range(h)]

cnt = [0]*(ord('z')-ord('a')+1)
for i in range(h):
    for j in range(w):
        cnt[ord(a[i][j])-ord('a')] += 1

f_num = 0
t_num = 0
for i in cnt:
    while i >= 4:
        i -= 4
        f_num += 1
    while i >= 2:
        i -=2
        t_num += 1

req_f = (h//2)*(w//2)
req_t = (h%2)*(w//2) + (w%2)*(h//2)

if req_f > f_num:
    print('No')
    exit()
f_num -= req_f
t_num += f_num*2
if req_t > t_num:
    print("No")
    exit()
print("Yes")
