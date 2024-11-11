line,times=map(int,input().split())
headortail=0
for i in range(line):
    if (i+1)%2 == 1 :
        for e in range(times):
            print("#",end='')
        print()
    else :
        if headortail == 0 :
            for l in range(times-1):
                print(".",end='')
            print("#")
            headortail =1
        else :
            print("#",end='')
            for l in range(times-1):
                print(".",end='')
            print()
            headortail =0
        
        
