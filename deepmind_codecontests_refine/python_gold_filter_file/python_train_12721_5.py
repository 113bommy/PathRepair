def solve():
        
        flag1 =False
        flag=False 
        cur =0
        mainnum=int(input())
        num = mainnum
        immediatenum =0
        for i in range(50,-1,-1):
            if pow(3,i)>num:
                immediatenum=pow(3,i)
                #print(immediatenum," ",i);
                flag1=True
                if(flag==True):
                   flag1= False
                cur=i
            elif pow(3,i)<num:
                #print(pow(3,i),end=" ")
                num = num-pow(3,i)
                flag= True
            else :
                return mainnum
        if(flag1==True):
            return immediatenum
        return int(mainnum-(immediatenum-1)/2+immediatenum-num)
for i in range(int(input())):
    print(solve())