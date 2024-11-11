n=int(input())
li=list(map(int,input().split()))
four,three,two,one=0,0,0,0
for i in range(0,n):
    if li[i]==4:
        four=four+1 
    if li[i]==3:
        three=three+1 
    if li[i]==2:
        two=two+1 
    if li[i]==1:
        one=one+1 

count=four+three
one=one-three


while two>0:
    if two%2==0 and two>1 :
        count=count+two/2
        two=0
        
    elif two%2!=0 and two>1:
        two=two-1
        count=count+two/2
        two=1 
        
        
    elif two>0 and two<2:
        count=count+two
        one=one-2
        two=0
        
while one>0:
    if(one>=4 and one%4==0):
        count=count+(one/4)
        one=0
        
    elif(one>4 and one%4!=0):
        x=one%4
        one=one-x
        count=count+(one/4)
        one=x
    elif(one>0 and one<4):
        count=count+1
        one=0
    
    
print(int(count))