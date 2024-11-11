__author__ = 'yarsanich'
n = int(input(''))
a = list(map(int,input().split()))
position = 0
inf = 0
ans_r = 0
step = 1
vector = 0
while inf!=n:
    if a[position] <= inf:
        inf += 1
        a[position] += 1000000
    if (inf!=n) and ((position == n - 1) or ((position == 0) and (vector))):
        ans_r += 1
        vector = 1
        step *= - 1
    position += step
print (ans_r)
