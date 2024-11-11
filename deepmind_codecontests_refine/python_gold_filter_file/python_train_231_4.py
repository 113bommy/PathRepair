number=int(input())
for i in range(number):
    number2=int(input())
    count2=0
    count3=0
    while(number2%2==0):
        number2=number2//2
        count2+=1
    while(number2%3==0):
        number2=number2//3
        count3+=1
    if(number2==1 and count2<=count3):
        print(2*count3-count2)
    else:
        print(-1)

    
    #number2=int(input())
    #count=0
    #while number2!=1:
        #if number2%6==0:
            #number2=number2//6
            #count+=1
        #elif number2%6!=0:
            #number2=number2*2
            #count+=1
        #else:
            #print(-1)

    #print(count)
