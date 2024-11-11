from sys import stdin
input=stdin.readline
try:
    for i in range(int(input())):
        s=input()
        count=0
        for j in s:
            if(j=='N'):
                count+=1
        if(count==1):
            print("no")
        if(count!=1):
            print("yes")
except:
    pass

