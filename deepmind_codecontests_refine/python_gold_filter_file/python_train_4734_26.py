from time import *
def sleuth(f): 
    if f[len(f)-2] in "aieEouAIOUyY" and f[len(f)-1]=="?":
        return"YES"
    else:
        return" NO"
k=input("")
count=0
j=""
abdo=''
n=''
for i in (k) :
    if count<=100:
        if i in  "ABCDEFGHIJKLMNOPQURSTVWXYZabcdefghijkulmnopqrstvwxyz":
            j=abdo+i
            n=j
            count+=1
        elif i=="?" :
            n=j+i
           
            break

print(sleuth(n))

