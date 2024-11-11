n=input()
for i in range(len(n)-1,-1,-1):
    if int(n[i])<=4:
        print("O-|"+"O"*int(n[i])+'-'+"O"*(4-int(n[i])))
    else:
        ans=int(n[i])
        ans%=5
        print("-O|"+"O"*ans+"-"+"O"*(4-ans))


