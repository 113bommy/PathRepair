#JMD
#Nagendra Jha-4096

 
import sys
import math

#import fractions
#import numpy
 
###File Operations###
fileoperation=0
if(fileoperation):
    orig_stdout = sys.stdout
    orig_stdin = sys.stdin
    inputfile = open('W:/Competitive Programming/input.txt', 'r')
    outputfile = open('W:/Competitive Programming/output.txt', 'w')
    sys.stdin = inputfile
    sys.stdout = outputfile

###Defines...###
mod=1000000007
 
###FUF's...###
def nospace(l):
    ans=''.join(str(i) for i in l)
    return ans
 
 
 
##### Main ####
t=1
for tt in range(t):
    n=int(input())
    s=n*(n+1)//2

    a=2
    flag=1
    while(2*a<=s):
        v1=a
        v2=s-a
        g=math.gcd(v1,v2)

        if(g>1):
            print("Yes")
            print(1,g)
            ans=[]
            for j in range(1,n+1):
                if(j!=g):
                    ans.append(j)
            print(n-1,*ans)
            flag=0
            break
        a+=1
    if(flag):
        print("No")
    #a=list(map(int,sys.stdin.readline().split(' ')))
    #n,k,s= map(int, sys.stdin.readline().split(' '))
    
    
#####File Operations#####
if(fileoperation):
    sys.stdout = orig_stdout
    sys.stdin = orig_stdin
    inputfile.close()
    outputfile.close()