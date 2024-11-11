n=input()
for j in range(len(n)-1,-1,-1):
    num=int(n[j])
    if(num>=5):
        print("-O|",end="")
        num=num-5
    else:
        print("O-|",end="")
    for _ in range(num):
        print("O",end="")
    print("-",end="")
    for k in range(4-num):
        print("O",end="")
    print("")
    