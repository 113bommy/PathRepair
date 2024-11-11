k=input()
k=int(k)
cnt=0
while k > 0:
    if k==0:
        break
    if k < 5 and k>=1:
        cnt +=k*1
        k=0
        
    if k>=5 and k<10:
        c = k//5
        k = k-5*c
        cnt += c
    elif k>=10 and k<20:
        c = k//10
        k = k-10*c
        cnt += c
        
    elif k>=20 and k<100:
        c = k//20
        k = k-20*c
        cnt += c
    elif k>=100:
        c = k//100
        k = k-100*c
        cnt += c
print(cnt)
