for n in range(int(input())):
    st=input()
    if(st[-2:]=="po"):
        print("FILIPINO")
    elif(st[-4:]=="desu" or st[-4:]=="masu"):
        print("JAPANESE")
    else:
        print("KOREAN")