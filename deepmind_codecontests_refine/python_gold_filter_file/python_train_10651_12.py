def tpg(x):
    for a in range(len(x)-1):
        if x[a]==x[a+1]:
            c=0
        else:
            c=1
            break
    if c==0:
        return 0
    else:
        for a in range(len(x)-1):
            if x[a]>x[a+1]:
                c=1
            else:
                c=2
                break
    if c==1:
        return 1
    else:
        return 2
        



n=int(input())

list_name=[]
taxi_num=[]
pizza_num=[]
girls_num=[]
for a in range(n):
    no,name=input().split()
    list_name.append(name)
    taxi=0
    pizza=0
    girls=0
    for aa in range(int(no)):
        c=input().split('-')
        c=''.join(c)
        res=tpg(c)
        if res==0:
            taxi+=1
        elif res==1:
            pizza+=1
        else:
            girls+=1
    taxi_num.append(taxi)
    pizza_num.append(pizza)
    girls_num.append(girls)


indices0 = [i for i, x in enumerate(taxi_num) if x == max(taxi_num)]      
indices1 = [i for i, x in enumerate(pizza_num) if x == max(pizza_num)]   
indices2 = [i for i, x in enumerate(girls_num) if x == max(girls_num)]        
     
p=5
q=5
r=5
       
if len(indices0)>1:
    p=0
if len(indices1)>1:
    q=0
if len(indices2)>1:
    r=0

if p==5:
    print('If you want to call a taxi, you should call: '+list_name[indices0[0]]+'.')    
elif p==0:
    print('If you want to call a taxi, you should call: ', end='' )
    for i in range(len(indices0)-1):
        print(list_name[indices0[i]],end=', ')
    print(list_name[indices0[-1]]+'.')    
        
       
if q==5:
    print('If you want to order a pizza, you should call: '+list_name[indices1[0]]+'.')    
elif q==0:
    print('If you want to order a pizza, you should call: ', end='' )
    for i in range(len(indices1)-1):
        print(list_name[indices1[i]],end=', ')
    print(list_name[indices1[-1]]+'.')   
    

    
if r==5:
    print('If you want to go to a cafe with a wonderful girl, you should call: '+list_name[indices2[0]]+'.')    
elif r==0:
    print('If you want to go to a cafe with a wonderful girl, you should call: ', end='')
    for i in range(len(indices2)-1):
        print(list_name[indices2[i]],end=', ')
    print(list_name[indices2[-1]]+'.')       

