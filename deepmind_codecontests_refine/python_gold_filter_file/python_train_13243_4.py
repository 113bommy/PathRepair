from sys import *
from math import *
from bisect import *
n,l=map(int,stdin.readline().split())
s=[]
for i in range(n):
    a=input()
    s.append(a)
x=set(s)
ans=0
for i in range(n-1):
    for j in range(i+1,n):
        z=""
        for k in range(l):
            if s[i][k]==s[j][k]:
                z+=s[i][k]
            else:
                if (s[i][k]=="S" or s[j][k]=="S") and (s[j][k]=="T" or s[i][k]=="T" ):
                    z+="E"
                if (s[i][k] == "S" or s[j][k] == "S") and (s[j][k] == "E" or s[i][k] == "E"):
                    z+="T"
                if (s[i][k] == "T" or s[j][k] == "T") and (s[j][k] == "E" or s[i][k] == "E"):
                    z+="S"
        if z in x:
            ans+=1

print(ans//3)