
pos = [0, 1, 2]

while len(pos) < 100001:
    a = pos[-1] + pos[-2]
    a %= 1000000007
    pos.append(a)

def solve():

    S = input() + "_"
    
    
    segs = []
    
    lU = 0
    lN = 0
    
    for s in S:
        if s == 'w' or s == 'm':
            print(0)
            return
        elif s == 'u':
            if lN > 1:
                segs.append(lN)
            lN = 0
            lU += 1
        elif s == 'n':
            if lU > 1:
                segs.append(lU)
            lU = 0
            lN += 1
        else:
            if lU > 1:
                segs.append(lU)

            if lN > 1:
                segs.append(lN)
            lU = 0
            lN = 0
    ans = 1
    
    for s in segs:
        ans *= pos[s]
        ans %= 1000000007
    print(ans)
    
solve()
                


                
                
                
                
                
            
            
            
                    
                
        