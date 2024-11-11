arr=[         list(  input()   )      for _ in range (8)      ]
cw=0
cb=0
flag = True
for i in range(0,8):
    for j in range(1,8):
        if ((arr[i][j]) == arr[i][j-1]) :
            flag =False
       
if  (flag == True):
    print("YES")
elif(flag == False):
    print("NO")