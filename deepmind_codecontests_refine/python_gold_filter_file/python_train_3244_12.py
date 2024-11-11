### http://codeforces.com/contest/1176/problem/B
 
def MyInput(Flag):
    return_list=[]
    if Flag:
        while True:
            try:
                a=input()
                if a:
                    return_list.append(a)
                else:
                    return return_list
                    break
            except EOFError:
                return return_list
    else:
        with open('input.txt') as f:
            return_list=f.read().split('\n')
            return return_list
 
def MyOutput(Flag, mystr):
    if Flag:
        print(mystr)
    else:
        with open('output.txt','a') as f:
            f.write(mystr+'\n')
            
 
flag=1
 
param=MyInput(flag)
count3=0
count2=0
count1=0
result=''
for i in range(int(param[0])):
    n=int(param.pop(1))
    an=[int(x1) for x1 in param.pop(1).split()]
    for x in an:
        
        if not x%3:
            count3+=1
            continue
        elif x%3==2:
            count2+=1
        else:
            count1+=1
            
    c1=abs(count2-count1)//3
    c2=min(count2,count1)
    count3=count3 + c1 + c2
    print(count3)
    count3=0
    count2=0
    count1=0