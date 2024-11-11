import sys
n=int(input())
time=str(input())
if n==12:
    if int(time[0:2])==00:
        time=time[:1]+"1"+time[2:]
    if int(time[0])>1:
        time="1"+time[1:3]+time[3:]    
    if int(time[0:2])<12 and int(time[3:])<60:
        print(time)
        sys.exit()
    if int(time[0:2])>12:
           time="0"+time[1:3]+time[3:] 
    if int(time[3:])>=60:
        time=time[:3]+"0"+time[4:]
    print(time)
    sys.exit()    
elif n==24:
    if int(time[0:2])<24 and int(time[3:])<60:
        print(time)
        sys.exit()
    if int(time[0:2])>23:
        time="0"+time[1:3]+time[3:]
            
    if int(time[3:])>=60:
        time=time[:3]+"0"+time[4:]
        
    print(time)
    sys.exit()
