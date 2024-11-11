# table tennis
from collections import deque

def TableTennis(pw, power):
    wins = 0
    power = deque(power)
    
    p1 = power.popleft()
    p2 = power[0]
    
    if len(power) == 1:
        if p1 > p2:
            print(p1)
        else:
            print(p2)
    else:
        while wins != pw[1]:
            if pw[1] > 500 and wins > 500 :
                break
            
            if p1 > p2:
                p2 = power.popleft()
                power.append(p2)
                p2 = power[0]
                wins += 1
            else: 
                power.append(p1)
                p2 = power.popleft()
                p1 = p2
                p2 = power[0]
                wins = 1
    
                
        print(p1)

pw = [int(x) for x in input().split()]
power = [int(x) for x in input().split()]
TableTennis(pw,power)