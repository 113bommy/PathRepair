n = int(input())

l = input()
l = [int(i) for i in l.split()]
r = 0
d = []
x = []
for i in range(n-1)  :
    if l[i]!=l[i+1]:
        d.append(l[i])
        x.append(i+1)

d.append(l[-1])
x.append(n)

a,b,c =  0 , 0 , 0 
for i in range(0 , len(d)-2):
    if d[i]>d[i+1] and d[i+1]<d[i+2]:
        print(3)
        print(x[i] , x[i+1] , x[i+2])
        r = 1
        break
    elif d[i]<d[i+1] and d[i+1]>d[i+2]:
        print(3)
        print(x[i] , x[i+1] , x[i+2])
        r = 1 ; break
if r==0:
    print(0)
