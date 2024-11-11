def magicPowder():
    ingredients, mps = map(int, input().split())
    need = [int(s) for s in input().split()]
    have = [int(s) for s in input().split()]
    low = 0
    high = 2000
    a = 0
    total = 0
    while(low <= high):
        mid = low + (high - low) // 2
        #print("low, high: ", low, high)
        #print("mid: ", mid)
        #print("need, have: ", need, have)
        #print("mps: ", mps)
        for i in range(ingredients):
            if need[i] * mid >= have[i]:
                total += need[i] * mid - have[i]
        #print("total: ", total)
        if total <= mps:
            low = mid + 1
            a = mid
        else:
            high = mid - 1
        total = 0
    #cookies = list(map(lambda n, h : int(h) // int(n), need, have))
    print(a)

magicPowder()
