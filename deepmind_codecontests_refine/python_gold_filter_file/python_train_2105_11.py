n=int(input())
str=input()
str=str.upper()
lc=0
rc=0
for i in range(n):
    if(str[i]=="L"):
        lc=lc-1
    elif(str[i]=="R"):
        rc=rc+1
count=((lc)*(-1))+(rc)+1
print(count)
