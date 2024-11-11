n = int(input())
for i in range(n):
    x , y = map(int , input().split()) ; step = 0
    a , b = max(x , y) , min(x , y)
    while a%b!=0:
        step= step + a//b 
        t = b ;  b = a%t ; a = t
        #print(step , a ,b)
    print(step+a//b)
        