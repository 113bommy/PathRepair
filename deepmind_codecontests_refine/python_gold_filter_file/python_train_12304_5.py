a , b = map(int , input().split(" "))

if b - a == 1 :
    print((str(a) +"9") , (str(b) +"0"))
elif a == b:
    print(int(str(a) +"1") , int(str(b) +"2"))
elif a == 9 and b == 1 :
    print(9 , 10)
else :
    print("-1")

