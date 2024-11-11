a=int(input())
i=0
g=0
while (i<a):
    i=i+1
    b=input()
    if str(b)=="X++" or str(b)=="++X":
        g+=1
    elif str(b)=="X--" or str(b)=="--X":
        g-=1
print(int(g))
