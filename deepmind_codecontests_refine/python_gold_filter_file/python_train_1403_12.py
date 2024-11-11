# coding: utf-8
n, k = [int(i) for i in input().split()]
temp = [int(i) for i in input().split()]
li = {}
for i in range(n):
    if temp[i] in li.keys():
        li[temp[i]].append(i)
    else:
        li[temp[i]] = [i]
cnt = 0
ans = []
for i in sorted(li.keys()):
    t = min(k//i,len(li[i]))
    k -= i*t
    cnt += t 
    ans += li[i][:t]
print(cnt)
print(' '.join([str(i+1) for i in ans]))
