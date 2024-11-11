t = int(input())
for zzz in range(t):
    count = 0
    stairCount = 0
    maxi = int(input())

    i = 1
    while True:
        if(count + (i * (i + 1) // 2) <= maxi):
            count = count + (i *(i + 1)// 2)
            stairCount += 1
            i = 2*i + 1
        else:
            break
    print(stairCount)
    