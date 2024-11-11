if __name__ == "__main__":
    nmk = input().split(' ')
    for i in range(len(nmk)):
        nmk[i] = int(nmk[i])
        
    m = nmk[1]
    k = nmk[2]
    prices = input().split(' ')
    
    for i in range(len(prices)):
        prices[i] = int(prices[i])

    avail_houses = list()
    for i in range(len(prices)):
        if prices[i] != 0 and k >= prices[i]:
            avail_houses.append(i+1)
    min_dist = len(prices)
    for h in avail_houses:
        if h - m < min_dist:
            min_dist = abs(h - m)
    print(min_dist*10)


    
  
        
            
        
            
    
            
    
    
    
    
    
