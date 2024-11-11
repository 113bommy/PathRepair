def factors(n):
    j=0
    if n>1:
        for i in range(1,int(n**(0.5))+1):
            if n%i==0:
                j+=2
        if int(n**(0.5))==n**(0.5):
            j-=1
        return j
    else:
        return 1

i=int(input())
print(factors(i))