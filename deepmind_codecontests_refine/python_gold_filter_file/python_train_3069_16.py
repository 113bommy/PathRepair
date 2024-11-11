weight1=0
weight2=0
for a in range(8):
    lst=input()
    for i in lst:
        if i=="Q":
            weight1+=9
        elif i=="q":
            weight2+=9
        elif i=="R":
            weight1+=5
        elif i=="r":
            weight2+=5
        elif i=="B":
            weight1+=3
        elif i=="b":
            weight2+=3
        elif i=="N":
            weight1+=3
        elif i=="n":
            weight2+=3
        elif i=="P":
            weight1+=1
        elif i=="p":
            weight2+=1
if weight1>weight2:
    print("White")
elif weight1<weight2:
    print("Black")
else:
    print("Draw")
