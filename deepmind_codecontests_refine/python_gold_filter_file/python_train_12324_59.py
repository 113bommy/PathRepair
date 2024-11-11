a=int(input())
x=0
for i in range(a):
    b=input()
    if b=='++X': 
        x=x+1
    elif b=='--X':
        x=x-1
    elif b=='X++':
        x=x+1
    elif b=='X--':
        x=x-1
print(x)
    
    
        
