n = int(input())
ss = input()

max_cnt = 0
for i in range(1, n):
    cnt = 0
    for j in range(n - i):
        if ss[j] == ss[j + i]:
            cnt += 1
            max_cnt = max(cnt, max_cnt)
            if cnt == i:
                break
        else:
            cnt = 0

print(max_cnt)