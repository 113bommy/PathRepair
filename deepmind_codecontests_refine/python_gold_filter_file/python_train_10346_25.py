n, k = map(int, input().split(sep=" "))
set = False
max = 0
for i in range(n):
    f, t = map(int, input().split(" "))
    if not set:
        set = True
        if t > k:
            max = f - (t - k) 
        else:
            max = f
    else:
        if t > k:
            if max < f-(t - k):
                max = f - (t - k) 
        else:
            if max < f:
                max = f
print(max)