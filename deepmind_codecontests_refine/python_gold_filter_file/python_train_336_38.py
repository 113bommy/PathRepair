n=int(input())
mod=10**9+7
fact=1
twos=1 
for i in range(1,n+1):
    fact=i*fact
    fact=fact%mod 
    if i!=1:
        twos*=2 
        twos=twos%mod 
print((fact-twos)%mod)
    