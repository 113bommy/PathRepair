n = int(input())
a = list(map(int, input().split()))
a.sort()
mex = 1
delta = 0
previous = 0
for i in a:
    delta += i - previous
    previous = i
    if delta > 0:
        delta -= 1
        mex += 1
print(mex )
