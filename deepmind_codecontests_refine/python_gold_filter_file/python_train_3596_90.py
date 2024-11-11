n , x = list(map(int,input().split()))
losser = 0
for i in range(n):
    sign , packs = input().split()
    if sign == '+':x += int(packs)
    elif sign == '-' and x >= int(packs):x -= int(packs)
    elif sign == '-' and x < int(packs): losser += 1
    
print(x,losser)