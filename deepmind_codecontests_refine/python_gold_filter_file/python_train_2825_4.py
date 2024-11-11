k=int(input())
s="47"
a="4"
b="7"
p=s
c="47"
def sum_d(s):
    summ1=0
    for i in s:
        summ1+=int(i)
    return summ1
def no_of_4_7(n):
    a=0
    flag=0
    if(a==n):
        a-=4
    while(a<=n):
        if((n-a)%7==0):
            no_7=(n-a)/7
            no_4=a/4
            
            if(no_4!=0 or no_7!=0):
                flag=1
                break
            else:
                flag=0
                a+=4
            
        
        else:

            a+=4
    if(flag==1):
        return no_7,no_4
    else:
        return -1;

if(no_of_4_7(k)==-1):
    print(-1)
else:
    a7,a4=no_of_4_7(k)
    for i in range(int(a4)):
        print(4,end="")
    for j in range(int(a7)):
        print(7,end="")
    print()
    
    
            
            