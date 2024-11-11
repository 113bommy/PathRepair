def antipalindrome():
    x=input()
    max=0
    k=0
    if(len(x)%2!=0):
        y=int((len(x)+1)/2)
    else:
        y=int(len(x)/2)
    for  i in range(len(x)):
        for j in range(i,y):
            if(x[j]!=x[len(x)-k-1]):
                max=len(x)-i
                return(max)
            k=k+1
        k=0
        s=len(x)-i
        if(s%2!=0):
            y=int((s+1)/2)
        else:
            y=int(s/2)
    return(max)
print(antipalindrome())