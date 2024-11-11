
def ispali(ss):
    if ss == ss[::-1]:
        return True
    return False

def compress(ss):
    cnt = []
    cmp = ""
    prev = '$'
    i = -1
    l = len(ss)
    while i < l-1:
        i += 1
        c = 1
        prev = ss[i]
        cmp += prev
        while i < l-1:
            i += 1
            
            if ss[i] == prev:
                c += 1
            else:
                i -= 1
                break
        
        cnt.append(c)
            
    
    return cmp , cnt

ss = input()

cmp , cnt = compress(ss)
lcmp = len(cmp)

if not ispali(cmp) or lcmp % 2 == 0 or cnt[ lcmp//2 ] < 2:
    
    print(0)

else:
    l = len(cnt)
    fir = cnt[ : l//2 ]
    nex = cnt[ l//2 + 1 : ]
    #reversed
    nex = nex[::-1]
    ans = True
    for a , b in zip( fir , nex ):
        
        if a+b < 3:
            ans = False
            break
    
    if ans:
        print( cnt[l//2] + 1 )
    else:
        print(0)
    
