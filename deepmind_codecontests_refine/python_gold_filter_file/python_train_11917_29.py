n=int(input())
p=0
i=0
ch=1
while n>=ch:
    i+=1
    ch+=i
    n-=ch
print(i)
