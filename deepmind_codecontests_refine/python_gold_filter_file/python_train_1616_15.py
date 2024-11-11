import sys
fl=0;sm=0;o=1;lg=0
n=int(input())
a=list(map(str,input().split(" ")))
for i in a:
    if (i=="0"):
        print(0)
        sys.exit()
    if ((i.count("1")==1) and (i.count("0")==len(i)-1)):
        sm+=i.count("0")
    else:
        fl=1
        o=i
print(o,end="")
print("0"*sm)
