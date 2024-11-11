q=10**9+7
max_limit=10**5+2
fibo=[1]*max_limit
fibo[0]=fibo[1]=1
for i in range(2,max_limit):
    fibo[i]=(fibo[i-1]+fibo[i-2])%q
s=input()+" "
no_string=False
u=n=0
a=b=1
for i in s:
    if i=='u':
        u+=1
    else:
        a=(a*[1,fibo[u]][u>0])%q
        u=0
    if i=='n':
        n+=1
    else:
        b=(b*[1,fibo[n]][n>0])%q
        n=0
    if i in ["m", "w"]:
        no_string = True
        break

print([(a*b)%q,0][no_string])