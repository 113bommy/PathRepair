import math
a=int(input())
for i in range(a):
        str1,int1,exp=map(int,input().split())
        if(exp==0):
            if(str1<=int1):
                print("0")
            else:
                print("1")
        else:
                print(min(exp+1,max(0,1+(str1-int1+exp)//2))) if(str1-int1+exp)%2!=0 else print(min(exp+1,max(0,(str1-int1+exp)//2)))
 