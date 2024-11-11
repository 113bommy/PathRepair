N = input().split()
A = int(N[0])
B = (N[1])
hasil =""
for i in range(A):
    if(B=="10"):
        if(i!=A-1):
            hasil+=B[0]
        else:
            hasil+=B[1]
    else:
        hasil+=B

if(A==1 and B=="10"):
    hasil=int(-1)
print(hasil)
