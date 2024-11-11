s = input()
t = input()
if (s==t):
    print("0")
elif(len(s)==1and len(t)==1 and s!=t):
    print("2")
else:
    i = 0
    j = 0
    n = 0
    if(len(s)>len(t)):
        i = len(t)-1
        j = len(s)-1
        flag = 1
        while(i>=0):
            if(t[i]==s[j]):
                 n+=1
            else :
                break
            i = i-1
            j = j-1

        n = n*2
        if(flag!=-1):
            print(len(s)+len(t)-n)
    else:
        i = len(s)-1
        j = len(t)-1
        while(i>=0):
            if(s[i]==t[j]):
                i= i-1
                j = j-1
                n+=1
            else:
                break
        n = n*2
        print(len(s)+len(t)-n)
