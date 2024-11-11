try:
    x=int(input())
    q=0
    while True:
        x=x-((q+2)*(q+1)//2)
        if x>=0:
            q=q+1
        else:
            break
    print(q)
except:
    pass
        
        
