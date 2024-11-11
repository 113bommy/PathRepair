c,v0,v1,a,l = map(int,input().split())

total = 0
days = 0
while(total<c):
    days+=1
    if(days==1):
        total +=min(v0,v1)
    else:
        total+= min (v1-l,v0+(a*(days-1))-l)
    
print(days)
    
    