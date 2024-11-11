import sys
a = input()
w = 0
count = 0

if len(a) == 1:
    if a[0] == "1":
        print("YES")
        sys.exit
    else:
        print("NO")
        sys.exit



for i in range(1,len(a)):
    
    if a[0] != "1":
        print("NO")
        break
    
    
    if a[i] != "1" and a[i] != "4":
        print("NO")
        break
    
    
    
    if a[i-1]+a[i] == "14":
        count += 1
    elif a[i-1]+a[i]  == "44":
        count += 1  
    elif a[i-1]+a[i]  == "41":
        count = 0
    #print(i,a[i-1]+a[i],count)
    
    if count >2:
        print("NO")
        break
    w = i
    

 
if w == len(a)-1 and len(a) > 1:
    print("YES")

