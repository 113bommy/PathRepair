for _ in range(int(input())):
    s=input()
    if(s[len(s)-2:len(s)]=="po"):
        print("Filipino".upper())
    elif(s[len(s)-4:len(s)]=="desu" or s[len(s)-4:len(s)]=="masu" ):
        print("Japanese".upper())
    else:
        print("Korean".upper())
