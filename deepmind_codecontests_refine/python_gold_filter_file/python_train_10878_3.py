peoplein= 0
capacity= 0
n= int(input())
data= [0 for i in range(1, (10**6)+ 10)]

for i in range(n):
    a, b= input().split()
    b= int(b)
    
    if a== "+":
        data[b]= 1
        peoplein+= 1
        capacity= max(capacity, peoplein)
    elif a== "-":
        if data[b]== 0:
            data[b]= -1
            #peoplein-= 1
            capacity+= 1
        elif data[b]== 1:
            data[b]= -1
            peoplein-= 1

print(capacity)
        