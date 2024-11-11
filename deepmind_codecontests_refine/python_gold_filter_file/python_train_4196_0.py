#coding:utf8
import itertools

cnt_case = int(input())

index = [0, 1, 2, 3]

a = [[0 for x in range(2)] for y in range(4)]
di = [0] * 100000
x = [0, 0, 0, 0]
y = [0, 0, 0, 0]


indexs = list(itertools.permutations(index, len(index)))
for i in range(len(indexs)):
    indexs[i]=list(indexs[i])


for i in range(cnt_case):
    res = 1000000000000
    cnt = 0
    for i in range(4):
        a[i][0], a[i][1] = [int(_v) for _v in input().split(" ")]
        for j in range(i):
            di[cnt] = abs(a[i][0] - a[j][0])
            cnt += 1
            di[cnt] = abs(a[i][1] - a[j][1])
            cnt += 1
    
    for _ind in indexs:
        for i in range(cnt):
            tmp_res = 0
            for k in range(4):
                x[k], y[k] = a[_ind[k]][0], a[_ind[k]][1]
            x[2] -= di[i]
            x[3] -= di[i]

            y[1] -= di[i]
            y[2] -= di[i]

            x = sorted(x)
            y = sorted(y)

            for i in range(4):
                tmp_res += abs(x[i] - x[2]) + abs(y[i] - y[2])
            
            res = min(res, tmp_res)
    
    print(res)