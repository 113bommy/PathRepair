def is_prime(a):
    return all(a%i for i in range(2,int(a**(1/2) +1)))
n = int(input())
l = n//2 
if n%2==0 :
    a = l 
else : a= l +1 
while  is_prime(a) or is_prime(l) :
    a+=1 ; l-=1 
print(l ," ", a)