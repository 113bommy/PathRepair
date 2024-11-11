g  = int(input())
total=0
for i in range(0,g):
    h= list(input())
    if(h[0]=="-" or h[1]=="-" or h[2]=="-"):
        total -=1
    elif(h[0]=="+" or h[1]=="+" or h[2]=="+"):
        total +=1
print (total)