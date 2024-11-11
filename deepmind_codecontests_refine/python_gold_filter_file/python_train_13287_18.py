n,a,b=map(int,input().split())
le=1
ri=min(a,b)+1
while le+1<ri:
    
    m=(le+ri)//2
    
    t=a//m+b//m
    
    if t<n:
        ri=m
    else:
        le=m
    
print(le)
