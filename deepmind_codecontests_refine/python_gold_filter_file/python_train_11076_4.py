a=input()
b=''
sh=0
sm=0
for i in range(0,len(a)-4):
    if a[i:i+5]=='heavy':
        sh+=1
    if a[i:i+5]=='metal':
        sm+=sh
print(sm)
    
    
