typee = int(input())
clock = input()
hours = clock[0:2]
minutes = clock[3:5]
if(typee == 12):
    if(int(hours) < 1 and int(minutes) >= 60):
        hours = hours[0]  + str(1)
        minutes = str(int(minutes[0]) - int(minutes[0])) + minutes[1]
    
    elif(int(hours) < 1 and int(minutes) < 60):
        hours = hours[0]  + str(1)
    elif(int(hours) <= 12 and int(minutes) < 60):
        hours = hours
        minutes = minutes
    elif(int(hours) <= 12 and int(minutes) >= 60):
        hours = hours
        minutes = str(int(minutes[0]) - int(minutes[0])) + minutes[1]
        
    elif(int(hours) > 12 and int(minutes) >= 60):
        hours = str(int(hours[0]) - int(hours[0]))  + hours[1]
        if(hours[1] == '0'):
                hours = '10'
        minutes = str(int(minutes[0]) - int(minutes[0])) + minutes[1]
    
    else:
        if(int(hours) > 21):
            hours = str(int(hours[0]) - int(hours[0]))  + hours[1]
            if(hours[1] == '0'):
                hours = '10'
        else:
            hours = str(int(hours[0]) - 1)  + hours[1]
    
else:
    if(int(hours) > 23):
        hours = str(int(hours[0]) - int(hours[0]))  + hours[1]
    if(int(minutes) >= 60):
        minutes = str(int(minutes[0]) - int(minutes[0])) + minutes[1]
    
print(hours + ':' + minutes) 
    
    