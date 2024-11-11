a, b = map(int,input().split())
counter = 0
for i in range(1,a+1):
    if i%2 != 0:
        print("#"*b)
    if i%2 == 0 :
        counter += 1  
        if counter % 2 !=0:
            print("."*(b-1)+ "#") 
        else:
            print("#"+"."*(b-1))