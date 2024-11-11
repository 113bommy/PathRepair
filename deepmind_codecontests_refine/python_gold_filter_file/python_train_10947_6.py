n=int(input())
for i in range(n):
    j=0
    x=int(input())
    while x!=1:
        if x%2==0:
            x=x//2
            j+=1
        elif x%3==0:
            x=2*x//3
            j+=1
        elif x%5==0:
            x=4*x//5
            j+=1
        else:
            j=-1
            print(j)
            break
    if j!=-1:
        print(j)
