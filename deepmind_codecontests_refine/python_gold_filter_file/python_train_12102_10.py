t = int(input())

for i in range(t):
    n, k = map(int, input().split())
    orgarr = list(map(int, input().split()))
    
    mostarr = [0] * n
    distinctnrs = []

    for number in orgarr:
        if not mostarr[number - 1]:
            mostarr[number - 1] = 1
            distinctnrs.append(number)
    
    if len(distinctnrs) < k:
        for i in range(k - len(distinctnrs)):
            distinctnrs.append(1)

    if len(distinctnrs) > k:
        print(-1)
    else:
        print(len(distinctnrs) * n)
        print(*(distinctnrs * n))




    



        
