m,n = str(input()).split(" ")
m,n = int(m), int(n)

area = m*n
if m*n%2==0:
    print(area//2)
elif m%2==0:
    if n==1:
        print(area//2)
    else:
        print(area//2 - m//2)
elif n%2==0:
    if m==1:
        print(area//2)
    else:
        print(area//2 - n//2)
else:
    print((area-1)//2)
