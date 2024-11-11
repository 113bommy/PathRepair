#from math import sqrt
def swap(i,j):
    t=string[i]
    string[i]=string[j]
    string[j]=t 
    

s=input().split()[0]
n=int(input())

a=[0]
inp=input().split()
for i in range(n):
    a.append(int(inp[i]))
#print(a)

a.sort()

string=dict()
for i in range(len(s)):
    string[i]=s[i]


j=len(a)-1
for i in range(int(len(s)/2),0,-1):
    while(a[j]>i):
       j-=1
       if (j<0):
           break
    #if (a[j+1]>=i):
    #    j+=1
    #print(i,j)
    if (a[j]<=i):
        kol=j
        #print(i,j,kol)
        if (kol%2==1):
            swap(i-1,len(s)-i)
    
    
    

out=""
for i in range(len(s)):
    out+=string[i]
print(out)
    
    
    
