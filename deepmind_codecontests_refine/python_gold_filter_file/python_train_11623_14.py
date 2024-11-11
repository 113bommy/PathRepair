

v = list(map(int,input().split()))

count = 0

if max(v[2],v[3]) <= min(2*v[2],2*v[3]):
    v[2] = min(max(v[2],v[3]),min(2*v[2],2*v[3]))

else:
    print(-1)
    count +=1
    
#-----------------------------------------------
if v[1] <= 2*v[2]+1 <= 2*v[1]:
    v[1] = 2*v[2]+1
elif v[1] > 2*v[2]:
    v[1] = v[1]
else:
    if count == 0:
        print(-1)
        count +=1
#---------------------------------------
        
               
if v[0] == v[1]:
    v[0] = v[1]+1
elif v[0] < v[1] < 2*v[0]:
    v[0] = v[1]+1
elif v[1] < v[0]:
    v[0] = v[0]
    
    

else:
    if count == 0:
        print(-1)
        count +=1
    
       
    
    
    

if count == 0:
    print(v[0])
    print(v[1])
    print(v[2])
    
    






