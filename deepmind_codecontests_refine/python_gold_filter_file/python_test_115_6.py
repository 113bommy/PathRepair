t=int(input())
while t:
    t -= 1
    n, h = map(int, input().split())
    a = [int(x)  for x in input().split()]
    dif = sorted(a2-a1 for a1,a2 in zip(a, a[1:]))
    # print(dif)
    isum=0
    for k in dif:
        if k > ((h-isum)//n): break
        isum += k
        n -=1
    print(0-(isum-h)//n)