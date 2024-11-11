a,b,c,d,e,f=map(int,input().split())
if a==0 and b*d>0 or c==0 and d>0:
    print("Ron")
else:    
    if a*c*e<b*d*f:
        print("Ron")
    else:
        print("Hermione")
