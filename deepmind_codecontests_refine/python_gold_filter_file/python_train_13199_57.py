N=int(input())
a=10**12
for i in range(1,int(N**.5)+1):
    if N%i==0:
        a=min(a,N//i+i-2)
print(min(N,a))
