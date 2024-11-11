n=int(input())
s=input()
r=s.count('R')
g=s.count('G')
b=s.count('B')
if (r>=1 and b>=1 and g>=1) or (r>=2 and b>=2) or (g>=2 and b>=2) or (r>=2 and g>=2) :
    print('BGR')
elif r==1 and b==1 :
    print('G')
elif r==1 and g==1 :
    print('B')
elif g==1 and b==1 :
    print('R')
elif (g>=2 and b==1) or (g>=2 and r==1) :
    print('BR')
elif (r>=2 and b==1) or (r>=2 and g==1) :
    print('BG')
elif (b>=2 and r==1) or (b>=2 and g==1) :
    print('GR')    
elif g==n :
    print('G')
elif r==n :
    print('R')
elif b==n :
    print('B')
