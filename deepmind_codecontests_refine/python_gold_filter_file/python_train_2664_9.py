n=int(input())
str=""
str+="VIBGYOR"*(n//7)
if n%7==1:
    str+="G"
elif n%7==2:
    str+="BG"
elif n%7==3:
    str+="IBG"
elif n%7==4:
    str+="IBGY"
elif n%7==5:
    str+="IBGYO"
elif n%7==6:
    str+="VIBGYO"
print(str)