times,length = input().split()
anse = int(length) -1
anse2  =  "."*anse
flag = 1
for i in range(1,int(times)+1,1):
    if(i%2 != 0):
        print("#"*int(length))
    else:
        if(flag == 1):
           print(anse2+"#")
           flag = 0
        else:
            print("#"+anse2)
            flag = 1
