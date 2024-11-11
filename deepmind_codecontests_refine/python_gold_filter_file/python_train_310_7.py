def primeq(x):
    if x==1:return False
    for i in range(2,int(x**.5)+1):
        if x%i==0:return False
    return True

c=0
for i in range(int(input())):
    if primeq(int(input())):c+=1
print(c)
