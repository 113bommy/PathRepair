def killJoy(x,n,ratings):
    initialInfection = 0

    for rating in ratings:
        if rating == x: initialInfection+=1
    
    if initialInfection == n: return 0

    if initialInfection >= 1: return 1

    summ = sum(ratings)

    if summ == x*n: return 1

    return 2

t=  int(input())

for _ in range(t):
    n, x = map(int, input().split())

    ratings = list(map(int, input().split()))

    print(killJoy(x,n, ratings))



    

