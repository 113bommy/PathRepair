n, m = map(int , input().split())
x, k, y = map(int , input().split())
arr = list(map(int , input().split()))
brr = list(map(int , input().split()))
used = [False for i in range(n + 1)]
f = True
res = 0

old, mx, idx, ln = 0, 0, 0, 0

def calc():
    global old, mx, idx, ln, res, f, i
    if ln < k:
        if old > mx or i > mx:
            res = res + ln * y
        else:
            f = False
        return
    if ln % k > 0:
        res = res + (ln % k) * y
        ln = ln - ln % k
    if x <= y * k:
        res = res + (ln // k) * x
    elif old > mx or i > mx:
        res = res + ln * y
    else:
        res = res + (ln - k) * y + x

for i in brr:
    if used[i] == True:
        f = False
        break
    #Stuff gonna start
    while idx < n:
        used[arr[idx]] = True
        if arr[idx] == i:
            idx = idx + 1
            break;
        mx = max(mx , arr[idx])
        ln = ln + 1
        idx = idx + 1
    calc()
    #Stuff gonna end
    old, mx, ln = i, 0, 0

while idx < n:
    mx = max(mx , arr[idx])
    ln = ln + 1
    idx = idx + 1


calc()


if f == False:
    print(-1)
else:
    print(res)
    
