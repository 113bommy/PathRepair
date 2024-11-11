n,c=map(int,input().split())
p=list(map(int,input().split()))
t=list(map(int,input().split()))
limak=0
rode=0
currtime=0

for i in range(n):
    currtime+=t[i]
    limak+=max(0,p[i]-c*currtime)
i=n-1
currtime=0
while i>=0:
    currtime+=t[i]
    rode+=max(0,p[i]-c*currtime)
    i-=1
if limak>rode:
    print("Limak")
elif rode>limak:
    print("Radewoosh")
else:
    print("Tie")
    




        
            
        
            
    
    
            
    
        

    
