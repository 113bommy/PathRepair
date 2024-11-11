n, t = map(int, input().split())
begin_num = 10**(n-1)
end_num = 10**n
flag = 0
for i in range(begin_num, end_num):
    if i % t == 0:
        print(i)
        flag = 1
        break
    else:
        continue
if flag == 0:
    print(-1) 