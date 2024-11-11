a,b=list(map(int,input().split()))
wina,winb,draw=0,0,0
for i in range(1,7):
    if(abs(i-a)>abs(i-b)):
        winb+=1
    elif(abs(i-a)<abs(i-b)):
        wina+=1
    else:
        draw+=1
print(wina,end=" ")
print(draw,end=" ")
print(winb,end=" ")