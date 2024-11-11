
cin = input().split()

a = int(cin[0])
b = int(cin[1])
f = int(cin[2])
k = int(cin[3])


fuel = [0]
for h in range(k // 2):
    fuel += [2 * a * h + f, 2 * a * (h + 1) - f]
if k%2 == 1 and k != 1:
    fuel += [2 * a * (k//2) + f]
elif k == 1:
    fuel += [f]
    
fuel += [a * k]

try:
    d1 = fuel[2] - fuel[1]
    d2 = fuel[3] - fuel[2]


except:
    d1 = fuel[1] - fuel[0]
    d2 = fuel[2] - fuel[1]
    
if d1 > b or d2 > b:
    print(-1)
    
else:
    fuelPointer = 0
    gas = b
    refuel = 0

    while fuelPointer < len(fuel) - 1:
        
        if gas < fuel[fuelPointer + 1] - fuel[fuelPointer]:
            refuel += 1
            gas = b
            
        gas -= (fuel[fuelPointer + 1] - fuel[fuelPointer])
        fuelPointer += 1
    
    print(refuel)
