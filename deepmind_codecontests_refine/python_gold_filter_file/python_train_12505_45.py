num = int(input())

a = -1
b = -1

if 1< num <=100:
    '''
    for i in range(1,num+1):
        for j in range(1,num):
            #print ('quem vem primeiro é a '+ str(i)+ ' quem vem por ultimo é b '+ str(j))
            if (i % j) == 0 and (i * j) > num and (j/i) < num and i!=j and i > j:
                a = i
                b = j
                break
               # print (str(a)+ ' ' + str(b) )


    if a != -1 and b != -1: 
        print (str(a)+ ' ' + str(b) )
    else:
        print(-1)'''
    print(str(num) + ' ' + str(num))
else :
    print(-1)