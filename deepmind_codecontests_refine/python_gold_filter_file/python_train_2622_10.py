for t in range(int(input())):
    sinp = input()
    
    subs = 0
    
    for l in range(1, min(20, len(sinp))+1):
        pz = 0
        
        for i in range(len(sinp)-l+1):
            if sinp[i] == '0':
                pz += 1
                continue
            
            binx = int(sinp[i:i+l], 2)
            
            if binx >= l and binx-l <= pz:
                subs += 1
            
            pz = 0
    
    print(subs)