t = int(input())*2;x=0;y=0;n=t//2
while t > 0 :
    t -= 1
    a,b=input().split()
    x+=int(a)
    y+=int(b)
print(x//n,y//n)