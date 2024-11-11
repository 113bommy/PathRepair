n = int(input())
A = []
B = []
Max1 = 0
Max2 = 0
c = 0
d = 0
Sum1 = 0
Sum2 = 0
for i in range(0,n):
    a,b = input().split()
    if int(a)-int(b)>Max1:
        Max1 = int(a)-int(b)
        c = i+1
    if int(b)-int(a)>Max2:
        Max2 = int(b)-int(a)
        d = i+1
                    
    Sum1 = Sum1 + int(a)
    Sum2 = Sum2 + int(b)
    
    A.append(int(a))
    B.append(int(b))
    
Max = max(Max1,Max2)   


if abs(Sum1-Sum2)>=Max:
    if Sum1 >=Sum2 and Max2>0:
        print(d)
    elif Sum1<Sum2 and Max1>0:
        print(c)
    else:
        print(0)
else:
    if Sum1 >=Sum2:
        print(c)
    else:
        print(d)

        
    
    
        
        
    
    
    