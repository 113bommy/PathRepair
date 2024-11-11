for i in range(int(input())):
    garland = list(map(int,input().split()))
    f = max(garland)
    garland.remove(f)
    if f-sum(garland)<=1:
        print("Yes")
    else:
        print("No")
