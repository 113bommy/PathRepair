x=0
for _ in range(int(input())):
    m=input()
    if(m=="X++" or m=="++X"):
        x+=1
    elif(m=="X--" or m=="--X"):
        x-=1
print(x)
    