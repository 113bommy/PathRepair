n = int(input())
x = int(input())

l0 = [1,2,2,1,0,0]
l1 = [0,0,1,2,2,1]
l2 = [2,1,0,0,1,2]

ind = n%6 - 1

if l0[ind] == x:
    print(0) 
elif l1[ind] == x:
    print(1) 
else:
    print(2)
     
    




    