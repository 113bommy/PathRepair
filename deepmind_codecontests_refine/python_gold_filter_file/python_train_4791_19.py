n = int(input())
klist = list(map(int,input().split()))
plist = []
i = 0
k = 1
a = 2**i-1
while 1:
    if klist[a:a+2**i] != []:
        plist.append(klist[a:a + 2**i])
    else: break
    a += 2**i
    i += 1
for i in range(len(plist)):
    for j in range(len(plist[i])):
        try:
            if i==0:
                print("node "+str(k)+": key = "+str(plist[0][0])+
                      ", left key = "+str(plist[1][0])+
                      ", right key = "+str(plist[1][1])+", ")
            else :
                l = int(j/2)
                print("node "+str(k)+": key = "+str(plist[i][j])+
                      ", parent key = "+str(plist[i-1][l])+", left key = "+
                      str(plist[i+1][2*j]),end="")
                try:
                    print(", right key = "+str(plist[i+1][2*j+1])+", ")
                except:
                    print(", ")
        except:
            l = int(j/2)
            print("node "+str(k)+": key = "+str(plist[i][j])+
                  ", parent key = "+str(plist[i-1][l])+", ")
        k += 1
