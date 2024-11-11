n=int(input())
s=input()

ish_slovo=[0 for i in range(n)]

if n%2!=0:
    co=n//2
    co2=n//2
    flag=False
    ish_slovo[n//2]=s[0]
    for ch in s[1:]:
        if flag:
            co+=1
            ish_slovo[co]=ch
            flag=False
            
        else:
            co2-=1
            ish_slovo[co2]=ch
            flag=True
        
else:
    co=(n//2)-1
    co2=(n//2)-1
    flag=False
    for ch in s:
        if flag:
            co+=1
            ish_slovo[co]=ch
            flag=False
            
        else:
            ish_slovo[co2]=ch
            flag=True
            co2-=1
print(''.join(ish_slovo))
