h1, h2=input("").split("|")
l=input("")
for i in range(len(l)):
    if(abs(len(h2)-len(h1)) <= len(l)):
        if(len(h1) < len(h2)):
            h1+=l[i]
        elif(len(h1) > len(h2)):
            h2+=l[i]
        else:
            h1+=l[i]
if(len(h1)==len(h2)):
    print(h1 + "|" + h2)
else:
    print("Impossible")