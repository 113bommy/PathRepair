num = int(input())
c = input().split()
for i in range(num):
    c[i] = int(c[i])
k = 0
listhl = []
if num < 3:
    print(0)
    k = 1
else:
    for i in range(1,num):
        if c[i] > c[i-1]:
            listhl.append("h")
        elif c[i-1] > c[i]:
            listhl.append("l")
        else:
            listhl.append("s")
    if listhl.count("h") > 0 and listhl.count("l") > 0:
        print("3")
        a = listhl.index("h")
        b = listhl.index("l")
        if a > b:
            print(b+1,a+1,a+2)
        else:
            print(a+1,b+1,b+2)
    else:
        print(0)
            
        
        
    
    

