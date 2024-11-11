t=int(input())
value = 0
for i in range(t):
    te =value
    x=input()
    if x == 'X++':
        value+=1
    elif x=='X--':
        value-=1
    elif x=='--X':
        value-=1
    elif x=='++X':
        value+=1

print(value)
        
        
        