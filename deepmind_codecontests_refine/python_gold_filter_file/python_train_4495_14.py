s=input()
n=len(s)

lkp=['a','e','i','o','u','y','A','E','I','O','U','Y']
jkl=list(s)
i=0
while i <n:
    if jkl[i] in lkp:
        del jkl[i]
        i-=1
        n-=1
    i+=1
k=0
i=0
while i<n:
    if jkl[i].islower():
        k+=1
    else:
        jkl[i]=jkl[i].lower()
    i+=1
for i in jkl:
    print(".",i,sep="",end="")