
def pot2mod(blancos,memo=[1]):
    if blancos < 0:
        return 0.5
    if blancos < len(memo):
        return memo[blancos]
        
    global NUMMOD
    for i in range(len(memo),blancos+1):
        memo.append((memo[i-1]*2)%NUMMOD)
    
    return memo[blancos]

NUMMOD = 998244353*8

if __name__ == "__main__":
    n, m = map(int,input().split())
    esblanco = [[False for x in range(m+1)]]
    for y in range(n):
        esblanco.append([False]+[x != '*' for x in input()])
    
    blancos = 0
    for renglon in esblanco:
        for x in renglon:
            if x:
                blancos+=1
    # print(blancos)
    blancos -= 2
    # print(pot2mod(blancos))
    suma = 0
    nume = [[0 for x in range(m+1)] for y in range(n+1)]
    numeren = 0
    denoren = 0
    # Recorre para sumar los dominos horizontales
    for y in range(1,n+1):
        for x in range(1,m+1):
            if esblanco[y][x] and esblanco[y][x-1]:
                denoren += 1
                numeren = (pot2mod(denoren)-numeren)%NUMMOD
                # print(numeren, pot2mod(blancos-denoren))
                suma += (numeren*pot2mod(blancos-denoren))%NUMMOD
            else:
                denoren = 0
                numeren = 0
            nume[y][x] = numeren/pot2mod(denoren)
    # for renglon in nume:
        # print(renglon)
    # print(suma)
    
    # Recorre para sumar los dominos horizontales
    for x in range(1,m+1):
        for y in range(1,n+1):
            if esblanco[y][x] and esblanco[y-1][x]:
                denoren += 1
                numeren = (pot2mod(denoren)-numeren)%NUMMOD
                suma += (numeren*pot2mod(blancos-denoren))%NUMMOD
            else:
                denoren = 0
                numeren = 0
            nume[y][x] = numeren/pot2mod(denoren)
                
    
    
    # for renglon in nume:
        # print(renglon)
    print(int(suma%(NUMMOD/8)))
    # for renglon in esblanco:
        # print(renglon)
    
    # result = pot2mod(blancos)
    # print(f"{result}")
