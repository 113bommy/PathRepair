def answer(n,s,t):
    if s==t:
        return 0
    c1s=0
    for i in s:
        if i=="1":
            c1s+=1
    c1t=0
    for i in t:
        if i=="1":
            c1t+=1
    if c1s!=c1t:
        return -1
    ones=0
    zeros=0
    for i in range(n):
        if s[i]=="1" and t[i]=="0":
            if zeros:
                zeros-=1
            ones+=1
            
        elif s[i]=="0" and t[i]=="1":
            if ones:
                ones-=1
            zeros+=1
    return zeros+ones
            


n=int(input())
s=input()
t=input()
print(answer(n,s,t))