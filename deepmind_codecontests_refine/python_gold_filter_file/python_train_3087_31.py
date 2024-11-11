n=int(input())
ch=input()
l=["a","e","i","o","u","y"]
b=0
ch1=""
for c in ch:
    if (c in l) and (b==0):
        b=1
        ch1=ch1+c
    elif not((c in l)):
        b=0
        ch1=ch1+c

print(ch1)
        
