count =0
N =int(input())

if N>=100 and N%100==0:
    count = N//100
    print(count)
    exit()
elif N>100:
    count+=N//100
    
    N=N%100

if N>=20 and N%20==0:
    count+=N//20
    print(count)
    exit()
elif N>20:
    while N>20:
        count+=1
        N-=20
if N>=10 and N%10==0:
    count+=N//10
    print(count)
    exit()
elif N>10:
    while N>10:
        count+=1
        N-=10
if N>=5 and N%5==0:
    count+=N//5
    print(count)
    exit()
elif N>5:
    while N>5:
        count+=1
        N-=5
print(count+N)