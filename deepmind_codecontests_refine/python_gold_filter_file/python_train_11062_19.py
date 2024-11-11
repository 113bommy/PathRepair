t = int(input())
while t:
    t-=1
    n = int(input())
    a = list(map(int, input().split()))
    ans =0
    tem=0
    if n==1:
        print(0)
        continue
    down = False
    ok=True
    for i in range(n-1,0,-1):
        if i==1:
            ok=False
        if down:
            if a[i]<a[i-1]:
                print(i)
                ok=True
                break
        else:
            if a[i]<=a[i-1]:
                continue
            else:
                down=True
    if ok:
        continue
    print(0)





