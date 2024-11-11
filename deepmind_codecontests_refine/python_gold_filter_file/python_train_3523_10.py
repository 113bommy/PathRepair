# https://atcoder.jp/contests/arc080/tasks/arc080_b

h,w = map(int,input().split())
n = int(input())
a = list(map(int,input().split()))

hw=[]
for i in range(n):
    hw+=([str(i+1)]*a[i])

flag = False
for i in range(h):
    bgn=i*w
    end=bgn+w
    res = hw[bgn:end]
    if flag:
        res=res[::-1]
        flag = False
    else:
        flag = True
    print(*res)