import math
game_score = int(input())

def verify_spent(score):
    for a in range(1000):
        for b in range(1000):
            c = (score - b*123456 - a*1234567)/1234
        
            if c >= 0 and (c - math.floor(c) == 0):
                print("YES")
                return
                
    print("NO")
                    
                    
verify_spent(game_score)
