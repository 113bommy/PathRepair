def good(s):
    n = len(s)
    if(n%2):
        return 1
    else:
        if((s.count("1")==(n//2)) and (s.count("0")==(n//2))):
            return 0
        else:
            return 1
n = int(input())
s = list(input())
if(n%2):
    print("1")
    print(*s,sep="")
else:
    if(not ((s.count("1")==(n//2)) and (s.count("0")==(n//2)))):
        print("1")
        print(*s,sep="")
    else:
        i = 1
        while(True):
            if(good(s[:i:]) and good(s[i::])):
                ans = i
                break
            else:
                i+=1
        print("2")
        print(*s[:ans:],sep = "", end = " ")
        print(*s[ans::],sep = "")