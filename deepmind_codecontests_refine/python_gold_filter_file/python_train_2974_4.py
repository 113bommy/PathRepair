dai=int(input())
s=input()
chay=list(range(3,dai+1,2))
chay.reverse()
for i in chay:
    tmp="o"
    tmp+="go"*int(((i-1)/2))
    s=s.replace(tmp,"***",)
print(s)