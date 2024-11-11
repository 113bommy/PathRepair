n = int(input())
s = [int (i) for i in input().split()]
k = [0 for i in range (101)]
flag = False;
for i in s:
    k[i]+=1
    if k[i]>2:
        flag = True;
        
b = k.count(1)//2
a = k.count(1)-b
if a==b:
    print ('YES')
    for i in s:
        if k[i] == 1 and a!=0:
            print('A',end ='');
            a-=1
            k[i]-=1
        elif k[i] == 1:
            print('B',end ='');
            k[i]-=1
        else:
            print('A',end ='');
elif (flag):
        print ('YES')
        for i in s:
            if k[i] == 1 and a!=0:
                print('A',end ='');
                a-=1;
                k[i]-=1
            elif k[i] == 1:
                print('B',end ='');
                k[i]-=1
                
            elif k[i] >2 and flag:
                print ('B', end='');
                flag = False;
            else:
                print('A',end = '');
else:
    print ('NO')
            