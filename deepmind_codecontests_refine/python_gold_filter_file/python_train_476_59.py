#codeforces problem
l=list(map(int, input().strip().split()))
time1= (l[0]*l[1])+(2*l[3])
time2= (l[0]*l[2]) + (2*l[4])

if time1 < time2:
    print('First')
elif time2 < time1:
    print('Second')
else:
    print('Friendship')
        
        
        
    
        
    
    
    
        
        
    
                    
            