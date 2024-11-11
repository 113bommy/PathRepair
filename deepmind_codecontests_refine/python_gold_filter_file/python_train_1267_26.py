summer,bef,aft = input().split()
summer = int(summer)
bef = int(bef)
aft = int(aft)
water = list(map(int, input().split()))
for x in range(summer):
        if water[x] == min(water[x:x+aft+1]) and water[x] == min(water[max(0,x-bef):max(0,x+1)]):
            print(x+1)
            break