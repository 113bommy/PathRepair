for _ in range(int(input())):
    am = int(input())
    arr = list(map(int,input().split()))
    m = 0
    for mass in range(am*2+1):
        was  = [False]*am
        t  = 0
        for i in range(am):
            for g in range(am):
                if (arr[i] + arr[g] == mass) and i!=g and ((not was[i]) and (not was[g])):
                    t+=1
                    was[i] = True
                    was[g] = True
                    break
        m = max(t,m)
    print(m)