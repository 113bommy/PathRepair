pri=pow(10,9)+7

s=input()
m=len(s)
val=int(s,2)
print((pow(2,m-1,pri)*val)%pri)
