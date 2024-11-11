k=int(input())


if(k==0):
    print(1,1)
    print(1)
    exit(0)




q=bin(100000)





t=pow(2,len(q)-1)-1

rem=bin(k)
rem=rem[2::]
rem='0'*(len(bin(t))-2-len(rem))+(rem)
alpha=0
for i in range(len(rem)):
    if(rem[i]=='0'):
        alpha+=pow(2,len(rem)-i-1)



ans=[t,k,0]

gns=[alpha,t,0]

tns=[0,k,k]

print(3,3)
print(*ans)
print(*gns)
print(*tns)
