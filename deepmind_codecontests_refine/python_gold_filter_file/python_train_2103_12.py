t= int(input())
for i in range(t):
    a , b,c,d,k = map(int,input().split())
    
    x = a//c 
    if a%c!=0 :
        x+=1
    y = b//d 
    if b%d!=0 :
        y+=1
    if k <(x+y):
        print(-1)
    else :
        print(x,y)